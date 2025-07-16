#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QWidget>
#include <QDateTime>
#include <QString>
#include <QListView>
#include <QTimerEvent>
#include <QSet>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);
    socket = new QTcpSocket(this);
    model = new QStringListModel(this);
    ui->listView->setModel(model);
    plotter = ui->widget;

    coleta = false;
    id = startTimer(1000);

    connect(ui->connectButton, &QPushButton::clicked, this, &MainWindow::conectarServidor);    // "Connect"
    connect(ui->disconnectButton, &QPushButton::clicked, this, &MainWindow::desconectarServidor); // "Disconnect"
    connect(ui->updateButton, &QPushButton::clicked, this, &MainWindow::atualizarListaMaquinas); // "Update"
    connect(ui->startButton,   &QPushButton::clicked, this, &MainWindow::iniciarColeta); // "Start"
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::pararColeta);    // "Stop"
    connect(ui->listView, &QListView::clicked, this, &MainWindow::onMaquinaSelecionada);
}

void MainWindow::conectarServidor(){
    address = ui->lineEdit->text();

    if(socket->state() != QAbstractSocket::ConnectedState){
        socket->connectToHost(address, 1234);

        if (socket->waitForConnected(3000)) {
            QMessageBox::information(this, "Conexão", "Conectado com sucesso!");
            atualizarListaMaquinas();
        } else {
            QMessageBox::warning(this, "Erro", "Falha na conexão com o servidor.");
        }
    }
    else{
        desconectarServidor();
        conectarServidor();
    }
}



void MainWindow::desconectarServidor(){
    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->disconnectFromHost();
        QMessageBox::information(this, "Desconexão", "Desconectado do servidor.");
    }
}

void MainWindow::onMaquinaSelecionada(const QModelIndex &index){
    QString ipSelecionado = model->data(index, Qt::DisplayRole).toString();
    qDebug() << "IP selecionado:" << ipSelecionado;
}

void MainWindow::atualizarListaMaquinas(){
    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->write("list\r\n");
        socket->waitForBytesWritten(3000);
        if (!socket->waitForReadyRead(3000)) {
            qDebug() << "Nenhum dado recebido.";
            return;
        }

        QStringList list;
        while (socket->bytesAvailable()) {
            QString linha = socket->readLine().replace("\n","").replace("\r","");
            if (!linha.isEmpty()) {
                list.append(linha);
                qDebug() << linha;
            }
        }

        model->setStringList(list);
    }
}

void MainWindow::iniciarColeta(){
    killTimer(id);
    int valueTimer = ui->timingSlider->value() * 1000;
    qDebug()<<"iniciada";
    id = startTimer(valueTimer);
    coleta = true;
}

void MainWindow::pararColeta(){
    coleta = false;
}

void MainWindow::coletarDados() {
    QString str;
    QStringList list;
    qint64 thetime;

    str = "get " + address+ " 30\r\n";
    qDebug() << "to get data...";

    if(socket->state() == QAbstractSocket::ConnectedState){
        if(socket->isOpen()){
            qDebug() << "reading...";
            socket->write(str.toUtf8());
            socket->waitForBytesWritten();
            socket->waitForReadyRead();

            while(socket->bytesAvailable()){
                str = socket->readLine().replace("\n","").replace("\r","");
                list = str.split(" ");

                if(list.size() == 2){
                    bool ok, okValue;
                    str = list.at(0);
                    thetime = str.toLongLong(&ok);
                    str = list.at(1);
                    times.append(thetime);
                    values.append(str.toInt(&okValue));
                    // qDebug() << thetime << ": " << str;
                }
            }
        }

        // ordenacao
        for(int i=0; i<times.size()-1; ++i){
            for(int j=i+1; j<times.size(); ++j){
                if(times[i] > times[j]){
                    std::swap(times[i],times[j]);
                    std::swap(values[i],values[j]);
                }
            }
        }

        qint64 min = *std::min_element(times.begin(), times.end());
        qint64 max = *std::max_element(times.begin(), times.end());
        qint64 minValue = *std::min_element(values.begin(), values.end());
        qint64 maxValue = *std::max_element(values.begin(), values.end());

        // normalizacao
        for(int i=0; i<times.size(); ++i){
            if(max!=min)
                times[i] = (times[i] - min) * width()/ (max-min);
            else
                times[i] = (times[i] - min) * width()/ (max-min+1);
            if(maxValue!=minValue)
                values[i] = height() - (values[i] - minValue) * height()/ (maxValue-minValue);
            else
                values[i] = height() - (values[i] - minValue) * height()/ (maxValue-minValue+1);
        }

        plotter->setData(values, times);
        values.clear();
        times.clear();
    }
}


void MainWindow::timerEvent(QTimerEvent *event){
    if(coleta){
        coletarDados();
    }
}

MainWindow::~MainWindow(){
    delete socket;
    delete plotter;
    delete ui;
}
