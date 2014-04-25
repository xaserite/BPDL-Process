#include <QPointF>
#include "drawingcursor.h"

drawingCursor::drawingCursor()
{
}

drawingCursor::drawingCursor(QPointF point){
    setX(point.x());
    setY(point.y());
}

drawingCursor::drawingCursor(double x, double y){
    setX(x);
    setY(y);
}

drawingCursor drawingCursor::operator +=(const drawingCursor &rhs){
    return drawingCursor(QPointF(x()+rhs.x(),y()+rhs.y()));
}

drawingCursor drawingCursor::operator =(const QPoint &add){
    return drawingCursor(QPointF(add));
}

drawingCursor drawingCursor::operator =(const QPointF &add){
    return drawingCursor(add);
}

void drawingCursor::xmove(double xoffset){
    setX(x()+xoffset);
}

void drawingCursor::ymove(double yoffset){
    setY(y()+yoffset);
}

void drawingCursor::xymove(double xoffset, double yoffset){
    xmove(xoffset);
    ymove(yoffset);
}

void drawingCursor::set(double x, double y){
    setX(x);
    setY(y);
}
