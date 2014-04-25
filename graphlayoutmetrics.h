#ifndef GRAPHLAYOUTDATA_H
#define GRAPHLAYOUTDATA_H

#include <QWidget>
#include <QWidget>
#include <QPaintEvent>
#include <QtGlobal>
#include <QPainter>

struct GraphLayoutMetrics{
    GraphLayoutMetrics();

    QSize Size;
    QPointF DataRange;
    QPointF MeshSizeInUnits;
    QPoint MeshEmphasis;
    QFont Font;
    unsigned marginSize;
    unsigned MarkSize;

    QPoint Origin();
    double xUnitsToPixels(double units);
    double yUnitsToPixels(double units);
    double xMeshWidthInPixels();
    double yMeshHeightInPixels();
    double xMeshEmphasisInPixels();
    double yMeshEmphasisInPixels();
    double xAxisHeight();
    double xAxisWidth();
    double yAxisHeight();
    double yAxisWidth();
    double textHeight();
    double textWidth();
    double textWidth(QString text);
};

#endif // GRAPHLAYOUTDATA_H
