#ifndef GRAPHCURVEDRAWER_H
#define GRAPHCURVEDRAWER_H

#include <QPainter>
#include "graphlayoutmetrics.h"
#include "graphcurve.h"

class GraphCurveDrawer
{
public:
    explicit GraphCurveDrawer(GraphLayoutMetrics *D, QPainter *pt);
    void draw(GraphCurve curve);

private:
    QPainter *painter;
    GraphLayoutMetrics *M;

    QPointFVec transCurveCoordsIntoPixels(QPointFVec coords);
    void drawTransCoords(QPointFVec coordVec);
};

#endif // GRAPHCURVEDRAWER_H
