#include "graphlayoutmetrics.h"

#include <QPen>
#include <QPainter>


GraphLayoutMetrics::GraphLayoutMetrics(){
    Size = QSize(800,320);
    DataRange = QPointF(100,100);
    MeshSizeInUnits = QPointF(5,5);
    MeshEmphasis = QPoint(2,2);
    Font = QFont();
    marginSize = 10;
    MarkSize = 3;
}

QPoint GraphLayoutMetrics::Origin(){
    return QPoint(marginSize + yAxisWidth(),Size.height()- marginSize - xAxisHeight());
}

double GraphLayoutMetrics::xUnitsToPixels(double units){
    return units*xAxisWidth()/DataRange.x();
}

double GraphLayoutMetrics::yUnitsToPixels(double units){
    return units*yAxisHeight()/DataRange.y();
}

double GraphLayoutMetrics::xMeshWidthInPixels(){
    return xUnitsToPixels(MeshSizeInUnits.x());
}

double GraphLayoutMetrics::yMeshHeightInPixels(){
    return yUnitsToPixels(MeshSizeInUnits.y());
}

double GraphLayoutMetrics::xMeshEmphasisInPixels(){
    return xMeshWidthInPixels()*MeshEmphasis.x();
}

double GraphLayoutMetrics::yMeshEmphasisInPixels(){
    return yMeshHeightInPixels()*MeshEmphasis.y();
}

double GraphLayoutMetrics::xAxisHeight(){
    return textHeight();
}

double GraphLayoutMetrics::xAxisWidth(){
    return Size.width() - 2*marginSize - yAxisWidth();
}

double GraphLayoutMetrics::yAxisWidth(){
    return textWidth();
}

double GraphLayoutMetrics::yAxisHeight(){
    return Size.height() - 2*marginSize - xAxisHeight();
}

double GraphLayoutMetrics::textHeight(){
    QFontMetrics fm(Font);
    return fm.height();
}

double GraphLayoutMetrics::textWidth(){
    QFontMetrics fm(Font);
    return fm.width(QString::number(DataRange.y()));
}

double GraphLayoutMetrics::textWidth(QString text){
    QFontMetrics fm(Font);
    return fm.width(text);
}
