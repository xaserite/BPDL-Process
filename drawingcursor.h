#ifndef DRAWINGCURSOR_H
#define DRAWINGCURSOR_H

#include <QPointF>

class drawingCursor : public QPointF
{
public:
    drawingCursor();
    drawingCursor(QPointF point);
    drawingCursor(double x, double y);
    drawingCursor operator +=(const drawingCursor &rhs);
    drawingCursor operator =(const QPoint &add);
    drawingCursor operator =(const QPointF &add);
    void xmove(double xoffset);
    void ymove(double yoffset);
    void xymove(double xoffset, double yoffset);
    void set(double x, double y);
};

#endif // DRAWINGCURSOR_H
