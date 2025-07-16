#ifndef PLOTTER_H
#define PLOTTER_H
#include <QWidget>

class Plotter : public QWidget
{
    Q_OBJECT
private:
    float tempo;
    int r, g, b;
    int x0, y0, x1, y1;
    QVector<qint64> values, times;

public:
    explicit Plotter(QWidget *parent = nullptr);

public slots:
    void setData(const QVector<qint64>& values, const QVector<qint64>& times);
    void paintEvent(QPaintEvent *event);
    void mudaCor(int r, int g, int b);
};


#endif // PLOTTER_H
