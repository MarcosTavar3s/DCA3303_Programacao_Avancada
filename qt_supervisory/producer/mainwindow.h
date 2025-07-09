#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QStringListModel>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void putData();
    void tcpConnect();
    void tcpDisconnect();
    void changeTimer();
    void stopSending();
    void timerEvent(QTimerEvent *event);

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QStringListModel *model;
    QStringList list;
    bool changeTimerState, send;
    int id, minValue, maxValue;
};
#endif // MAINWINDOW_H
