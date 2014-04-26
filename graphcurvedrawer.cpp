#include "graphcurvedrawer.h"
#include <iterator>
#include <QList>

GraphCurveDrawer::GraphCurveDrawer(GraphLayoutMetrics *D, QPainter *pt){
    painter = pt;
    M = D;
}

void GraphCurveDrawer::draw(GraphCurve curve){
    QPointFVec coordVec = transCurveCoordsIntoPixels(curve.getCoordinates());
    drawTransCoords(coordVec);
}

QPointFVec GraphCurveDrawer::transCurveCoordsIntoPixels(QPointFVec coords){
    QPointFVec trans;
    foreach(QPointF p,coords){
        QPointF ptrans = M->Origin() + QPointF(M->xUnitsToPixels(p.x()),-M->yUnitsToPixels(p.y()));
        trans.append(ptrans);
    }
    return trans;
}

void GraphCurveDrawer::drawTransCoords(QPointFVec coordVec){
    QPointFVec::iterator i;
    for(i=coordVec.begin();(i+1)!=coordVec.end();++i){
        painter->drawLine(*i,*(i+1));
    }
}
