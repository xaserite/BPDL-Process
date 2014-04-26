#ifndef GRAPHCURVE_H
#define GRAPHCURVE_H

#include <QList>
#include <QColor>
#include <QVector>
#include <QString>
#include <QPointF>

typedef QVector<QPointF> QPointFVec;

class GraphCurve
{
public:
    GraphCurve(QString label);
    GraphCurve(QPointFVec Coords, QString label);
    GraphCurve(QVector<double> xPoint, QVector<double> yPoint, QString);

    QPointFVec getCoordinates();
    QString getLabel();
    double xPointMax();
    double yPointMax();
    void appendQPointF(QPointF point);
    void appendQPointFs(QPointFVec points);
    void appendQVectors(QVector<double> x, QVector<double> y);
    bool hasLabel(QString label);

private:
    QString Label;
    QPointFVec Coordinates;
    QColor CurveColor;
    bool isAppendable(QPointF point);

    void extractCoordinates(QVector<double> xPoint, QVector<double> yPoint);
    void extractSingleCoordinate(int index, QVector<double> xPoint, QVector<double> yPoint);
};

typedef QList<GraphCurve*> GraphCurveList;

#endif // GRAPHCURVE_H
