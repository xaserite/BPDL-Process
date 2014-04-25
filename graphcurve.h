#ifndef GRAPHCURVE_H
#define GRAPHCURVE_H

#include <QList>
#include <QColor>
#include <vector>
#include <QString>
#include <QPointF>

typedef std::vector<QPointF*> QPointFVec;

class GraphCurve
{
public:
    GraphCurve();
    GraphCurve(QPointFVec Coords, QString label);
    GraphCurve(std::vector<double> xPoint, std:: vector<double> yPoint, QString);

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
