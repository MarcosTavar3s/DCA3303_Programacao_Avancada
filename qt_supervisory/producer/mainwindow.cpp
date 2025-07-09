#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QString>
#include <QListView>
#include <QMessageBox>
#include <QTimerEvent>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    // para o list viewer
    model = new QStringListModel(this);

    // inicializacao do timer
    id = startTimer(1000);

    // evita que comece enviando
    send = false;
    changeTimerState = false;

    // inicializacao min e max do numero aleatorio
    minValue = 0;
    maxValue = 35;

    QStringList list;

    model->setStringList(list);
    ui->listView->setModel(model);

    connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(tcpConnect()));
    connect(ui->disconnectButton, SIGNAL(clicked()), this, SLOT(tcpDisconnect()));
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(changeTimer()));
    connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(stopSending()));

}

void MainWindow::tcpConnect(){
    QString address = ui->textBox->text();
    socket->connectToHost(address, 1234);

    if(socket->state() != QAbstractSocket::ConnectedState){
        if (socket->waitForConnected(3000)) {
            qDebug() << "Connected";
            ui->connectionLabel->setText("connected");
            ui->textBox->clear();
        } else {
            QString warningMsg = socket->errorString();
            QMessageBox msgBox;
            msgBox.setWindowTitle("Warning");
            msgBox.setText(warningMsg);
            msgBox.exec();

            qDebug() << "Disconnected " << socket->errorString();
            ui->connectionLabel->setText("disconnected");
        }
    }
    else{
        tcpDisconnect();
        tcpConnect();
    }


}

void MainWindow::tcpDisconnect(){
    if(socket->state() == QAbstractSocket::ConnectedState){
        socket->disconnectFromHost();
        qDebug() << "Disconnected";
        ui->connectionLabel->setText("disconnected");
    }
}

void MainWindow::putData(){
    QString str;
    qint64 msecdate;


    if (socket->state() == QAbstractSocket::ConnectedState) {

        msecdate = QDateTime::currentDateTime().currentMSecsSinceEpoch();
        str = "set " + QString::number(msecdate) + " " +
              QString::number(minValue + rand() % (maxValue - minValue)) + "\r\n";

        qDebug() << str;
        qDebug() << socket->write(str.toStdString().c_str()) << " bytes written";

        list.append(str.toStdString().c_str());

        model->setStringList(list);
        ui->listView->setModel(model);

        if (socket->waitForBytesWritten(3000)) {
            qDebug() << "wrote";
        }
    }
}

void MainWindow::changeTimer(){
    changeTimerState = true;
    send = false;
}

void MainWindow::stopSending(){
    send = false;
}

void MainWindow::timerEvent(QTimerEvent *event){
    if(changeTimerState){
        killTimer(id);
        int valueTimer = ui->timingSlider->value() * 1000;
        id = startTimer(valueTimer);

        if(ui->maxSlider->value() > minValue){
            maxValue = ui->maxSlider->value();
            qDebug() << "Max:" << maxValue;
        }

        if(ui->minSlider->value() < maxValue){
            minValue = ui->minSlider->value();
            qDebug() << "Min:" << minValue;
        }

        // qDebug() << ui->timingSlider->value();
        changeTimerState = false;
        send = true;
    }

    if(send){
        putData();
    }
}

MainWindow::~MainWindow(){
    delete socket;
    delete model;
    delete ui;
}
