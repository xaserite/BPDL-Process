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
    GraphCurve(std::vector<double> xPoint, std:: vector<double> yPoint, QString);

    QPointFVec getCoordinates();
    QString getLabel();
    double xPointMax();
    double yPointMax();
    void appendQPointF(QPointF point);
    void appendQPointFs(QPointFVec points);
    bool hasLabel(QString label);

private:
    QString Label;
    QPointFVec Coordinates;
    QColor CurveColor;

    void extractCoordinates(std::vector<double> xPoint, std:: vector<double> yPoint);
    void extractSingleCoordinate(size_t index, std::vector<double> xPoint, std:: vector<double> yPoint);
};

typedef QList<GraphCurve*> GraphCurveList;

#endif // GRAPHCURVE_H
