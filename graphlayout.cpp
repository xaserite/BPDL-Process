#include "graphlayout.h"

GraphLayout::GraphLayout(GraphLayoutMetrics *D,QPainter *pt)
{
    painter = pt;
    M = D;
    font = D->Font;
    xRangeInUnits = D->DataRange.x();
    yRangeInUnits = D->DataRange.y();
    xWidthInPixels = D->Size.width();
    yHeightInPixels = D->Size.height();
    marginSize = D->marginSize;
    MarkLength = D->MarkSize;
    xMeshWidthInUnits = D->MeshSizeInUnits.x();
    yMeshHeightInUnits = D->MeshSizeInUnits.y();
    xMeshEmphasisStep = D->MeshEmphasis.x();
    yMeshEmphasisStep = D->MeshEmphasis.y();
    drawingEndCursor = drawingStartCursor = QPointF(0,0);
}

void GraphLayout::drawLayout(){
    drawAxes();
    drawMesh();
    drawMarks();
}

void::GraphLayout::drawAxes(){
    initPenWide();
    drawXAxis();
    drawYAxis();
}

void GraphLayout::drawMesh(){
    initPenDotted();
    drawXMesh();
    drawYMesh();
}

void GraphLayout::drawMarks(){
    initPenBlack();
    drawXAxisMarks();
    drawYAxisMarks();
    initPenWide();
    drawXAxisMarkEmphasis();
    drawYAxisMarkEmphasis();
}

void GraphLayout::drawNumbers(){
    drawXAxisNumbers();
    drawYAxisNumbers();
}

void GraphLayout::drawXAxis(){
    initXAxis();
    drawLine();
    drawXAxisArrow();
}

void GraphLayout::drawYAxis(){
    initYAxis();
    drawLine();
    drawYAxisArrow();
}

void GraphLayout::drawXMesh(){
    initYAxis();
    for(double pos=0;pos<xRangeInUnits;pos+=xMeshWidthInUnits*xMeshEmphasisStep)
        drawXMeshSingleLine();
}

void GraphLayout::drawYMesh(){
    initXAxis();
    for(double pos=0;pos<yRangeInUnits;pos+=yMeshHeightInUnits*yMeshEmphasisStep)
        drawYMeshSingleLine();
}

void GraphLayout::drawXAxisMarks(){
    initXAxisMarks();
    for(double pos=0;pos<xRangeInUnits;pos+=xMeshWidthInUnits)
        drawXAxisSingleMark();
}

void GraphLayout::drawYAxisMarks(){
    initYAxisMarks();
    for(double pos=0;pos<yRangeInUnits;pos+=yMeshHeightInUnits)
        drawYAxisSingleMark();
}

void GraphLayout::drawXAxisMarkEmphasis(){
    initXAxisMarkEmphasis();
    for(double pos=0;pos<xRangeInUnits;pos+=xMeshWidthInUnits*xMeshEmphasisStep)
        drawXAxisSingleEmphasisedMark();
}

void GraphLayout::drawYAxisMarkEmphasis(){
    initYAxisMarkEmphasis();
    for(double pos=0;pos<yRangeInUnits;pos+=yMeshHeightInUnits*yMeshEmphasisStep)
        drawYAxisSingleEmphasisedMark();
}

void GraphLayout::drawXAxisNumbers(){
    for(double pos=0;pos<xRangeInUnits;pos+=xMeshWidthInUnits*xMeshEmphasisStep)
        drawXAxisSingleNumber(pos);
}

void GraphLayout::drawYAxisNumbers(){
    for(double pos=0;pos<yRangeInUnits;pos+=yMeshHeightInUnits*yMeshEmphasisStep)
        drawXAxisSingleNumber(pos);
}

void GraphLayout::drawXAxisArrow(){
    drawingStartCursor.set(xWidthInPixels - marginSize, yHeightInPixels- marginSize - M->xAxisHeight());
    drawingEndCursor.set(drawingStartCursor.x() - 2*MarkLength, drawingStartCursor.y() + 2*MarkLength);
    drawLine();
}

void GraphLayout::drawYAxisArrow(){
    drawingStartCursor.set(marginSize + M->yAxisWidth(),marginSize);
    drawingEndCursor.set(drawingStartCursor.x() - 2*MarkLength,drawingStartCursor.y() + 2*MarkLength);
    drawLine();
}

void GraphLayout::drawXMeshSingleLine(){
    drawingStartCursor.xmove(M->xMeshEmphasisInPixels());
    drawingEndCursor.xmove(M->xMeshEmphasisInPixels());
    drawLine();
}

void GraphLayout::drawYMeshSingleLine(){
    drawingStartCursor.ymove(-M->yMeshEmphasisInPixels());
    drawingEndCursor.ymove(-M->yMeshEmphasisInPixels());
    drawLine();
}

void GraphLayout::drawXAxisSingleMark(){
    drawLine();
    drawingStartCursor.xmove(M->xMeshWidthInPixels());
    drawingEndCursor.xmove(M->xMeshWidthInPixels());
}

void GraphLayout::drawYAxisSingleMark(){
    drawLine();
    drawingStartCursor.ymove(-M->yMeshHeightInPixels());
    drawingEndCursor.ymove(-M->yMeshHeightInPixels());
}

void GraphLayout::drawXAxisSingleEmphasisedMark(){
    drawLine();
    drawingStartCursor.xmove(M->xMeshEmphasisInPixels());
    drawingEndCursor.xmove(M->xMeshEmphasisInPixels());
}

void GraphLayout::drawYAxisSingleEmphasisedMark(){
    drawLine();
    drawingStartCursor.ymove(-M->yMeshEmphasisInPixels());
    drawingEndCursor.ymove(-M->yMeshEmphasisInPixels());
}

void GraphLayout::drawXAxisSingleNumber(double number){
    QString string = QString::number(number);
    drawingStartCursor.xymove(-M->textWidth(string)/2,M->textHeight()+MarkLength*1.1);
    painter->drawText((drawingStartCursor), string);
}

void GraphLayout::drawYAxisSingleNumber(double number){
    QString string = QString::number(number);
    drawingStartCursor.xymove(-M->textWidth(string)/2,M->textHeight()+MarkLength*1.1);
    painter->drawText((drawingStartCursor), string);
}

void GraphLayout::drawLine(){
    painter->drawLine(drawingStartCursor, drawingEndCursor);
}

void GraphLayout::initOrigin(){
    drawingStartCursor.set(marginSize + M->yAxisWidth(),yHeightInPixels- marginSize - M->xAxisHeight());
}

void GraphLayout::initXAxis(){
    initOrigin();
    drawingEndCursor.set(drawingStartCursor.x()+M->xAxisWidth(),drawingStartCursor.y());
}

void GraphLayout::initYAxis(){
    initOrigin();
    drawingEndCursor.set(drawingStartCursor.x(),drawingStartCursor.y()-M->yAxisHeight());
}

void GraphLayout::initXAxisMarks(){
    initOrigin();
    drawingEndCursor.set(drawingStartCursor.x(),drawingStartCursor.y()+MarkLength);
}

void GraphLayout::initYAxisMarks(){
    initOrigin();
    drawingEndCursor.set(drawingStartCursor.x()-MarkLength,drawingStartCursor.y());
}

void GraphLayout::initXAxisMarkEmphasis(){
    initOrigin();
    drawingEndCursor.set(drawingStartCursor.x(),drawingStartCursor.y()+MarkLength*2);
}

void GraphLayout::initYAxisMarkEmphasis(){
    initOrigin();
    drawingEndCursor.set(drawingStartCursor.x()-MarkLength*2,drawingStartCursor.y());
}

void GraphLayout::initXAxisNumbers(){
    drawingStartCursor.set(marginSize+M->yAxisWidth(),yHeightInPixels-marginSize);
}

void GraphLayout::initYAxisNumbers(){
    drawingStartCursor.set(marginSize+M->yAxisWidth()/2,yHeightInPixels- marginSize - M->xAxisHeight());
}

void GraphLayout::initPenBlack(){
    painter->setPen(QPen(QColor(qRgb(0, 0, 0))));
}

void GraphLayout::initPenDotted(){
    QPen pen;
    pen.setStyle(Qt::DotLine);
    painter->setPen(pen);
}

void GraphLayout::initPenCoarse(){
    QPen pen;
    pen.setWidthF(1);
    painter->setPen(pen);
}

void GraphLayout::initPenWide(){
    QPen pen;
    pen.setWidthF(2.0);
    pen.setCapStyle(Qt::RoundCap);
    painter->setPen(pen);
}
