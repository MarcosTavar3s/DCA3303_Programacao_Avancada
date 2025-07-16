#include "plotter.h"

#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QDebug>

Plotter::Plotter(QWidget *parent): QWidget{parent}{
    r = 255;
    g = 255;
    b = 200;
    x0 = y0 = x1 = y1 =0;
}

void Plotter::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    painter.setRenderHint(QPainter::Antialiasing);

    brush.setColor(QColor(r,g,b));
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.drawRect(rect());


    pen.setColor(QColor(255,0,0));
    pen.setWidth(2);
    painter.setPen(pen);


    if (values.size() < 2 || times.size() < 2 || values.size() != times.size()) {
        qDebug() << "Tamanhos diferentes";
        return;
    }

    for (int i = 0; i < values.size() - 1; ++i) {
        x0 = times[i];
        x1 = times[i+1];
        y0 = values[i];
        y1 = values[i+1];
        painter.drawLine(x0, y0, x1, y1);
    }
}

void Plotter::setData(const QVector<qint64>& values, const QVector<qint64>& times) {
    this->values = values;
    this->times = times;
    // qDebug() << values;
    update();
}

void Plotter::mudaCor(int r, int g, int b){
    this->r = r;
    this->g = g;
    this->b = b;
}
