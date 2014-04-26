#ifndef HELPER_H
#define HELPER_H

#include <QPainter>
#include <QFontMetricsF>
#include <QPointF>
#include <QPen>
#include <QBrush>
#include <QVector>

namespace helper{

bool areSameLength(QVector<double> x, QVector<double> y){
    return (x.size()==y.size()) ? true : false;
}

double takeGreater(double a, double b){
    return (a > b) ? a : b;
}
}

#endif // HELPER_H
