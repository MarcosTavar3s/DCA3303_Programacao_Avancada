#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QTcpServer>
#include <QStringListModel>
#include <QSet>
#include "plotter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void conectarServidor();
    void desconectarServidor();
    void atualizarListaMaquinas();
    void iniciarColeta();
    void pararColeta();
    void coletarDados();
    void onMaquinaSelecionada(const QModelIndex &index);
    void timerEvent(QTimerEvent *event);

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QStringListModel *model;
    QStringList list;
    QSet<QString> listaIps;
    QString address;
    QVector<qint64> values, times;
    class Plotter *plotter;
    bool coleta;
    int id;

};

#endif // MAINWINDOW_H
