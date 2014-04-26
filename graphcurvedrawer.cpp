#include "graphcurvedrawer.h"
#include <iterator>
#include <QList>

GraphCurveDrawer::GraphCurveDrawer(GraphLayoutMetrics *D, QPainter *pt){
    painter = pt;
    M = D;
}

void GraphCurveDrawer::draw(GraphCurve curve){
    QList<GraphCurve*>::iterator i;
        painter->drawLines(curve.getCoordinates());
}
