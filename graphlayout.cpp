#include "graphlayout.h"

GraphLayout::GraphLayout(GraphLayoutMetrics *D,QPainter *pt)
{
    painter = pt;
    M = D;
    drawingEndCursor = drawingStartCursor = QPointF(0,0);
}

void GraphLayout::updateGraphLayout(QPointF Range){
    M->DataRange = Range;
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
    for(double pos=0;pos<M->DataRange.x();pos+=M->MeshSizeInUnits.x()*M->MeshEmphasis.x())
        drawXMeshSingleLine();
}

void GraphLayout::drawYMesh(){
    initXAxis();
    for(double pos=0;pos<M->DataRange.y();pos+=M->MeshSizeInUnits.y()*M->MeshEmphasis.y())
        drawYMeshSingleLine();
}

void GraphLayout::drawXAxisMarks(){
    initXAxisMarks();
    for(double pos=0;pos<M->DataRange.x();pos+=M->MeshSizeInUnits.x())
        drawXAxisSingleMark();
}

void GraphLayout::drawYAxisMarks(){
    initYAxisMarks();
    for(double pos=0;pos<M->DataRange.y();pos+=M->MeshSizeInUnits.y())
        drawYAxisSingleMark();
}

void GraphLayout::drawXAxisMarkEmphasis(){
    initXAxisMarkEmphasis();
    for(double pos=0;pos<M->DataRange.x();pos+=M->MeshSizeInUnits.x()*M->MeshEmphasis.x())
        drawXAxisSingleEmphasisedMark();
}

void GraphLayout::drawYAxisMarkEmphasis(){
    initYAxisMarkEmphasis();
    for(double pos=0;pos<M->DataRange.y();pos+=M->MeshSizeInUnits.y()*M->MeshEmphasis.y())
        drawYAxisSingleEmphasisedMark();
}

void GraphLayout::drawXAxisNumbers(){
    for(double pos=0;pos<M->DataRange.x();pos+=M->MeshSizeInUnits.x()*M->MeshEmphasis.x())
        drawXAxisSingleNumber(pos);
}

void GraphLayout::drawYAxisNumbers(){
    for(double pos=0;pos<M->DataRange.y();pos+=M->MeshSizeInUnits.y()*M->MeshEmphasis.y())
        drawXAxisSingleNumber(pos);
}

void GraphLayout::drawXAxisArrow(){
    drawingStartCursor.set(M->Size.width() - M->marginSize, M->Size.height()- M->marginSize - M->xAxisHeight());
    drawingEndCursor.set(drawingStartCursor.x() - 2*M->MarkSize, drawingStartCursor.y() + 2*M->MarkSize);
    drawLine();
}

void GraphLayout::drawYAxisArrow(){
    drawingStartCursor.set(M->marginSize + M->yAxisWidth(),M->marginSize);
    drawingEndCursor.set(drawingStartCursor.x() - 2*M->MarkSize,drawingStartCursor.y() + 2*M->MarkSize);
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
    drawingStartCursor.xymove(-M->textWidth(string)/2,M->textHeight()+M->MarkSize*1.1);
    painter->drawText((drawingStartCursor), string);
}

void GraphLayout::drawYAxisSingleNumber(double number){
    QString string = QString::number(number);
    drawingStartCursor.xymove(-M->textWidth(string)/2,M->textHeight()+M->MarkSize*1.1);
    painter->drawText((drawingStartCursor), string);
}

void GraphLayout::drawLine(){
    painter->drawLine(drawingStartCursor, drawingEndCursor);
}

void GraphLayout::initOrigin(){
    drawingStartCursor.set(M->marginSize + M->yAxisWidth(),M->Size.height()- M->marginSize - M->xAxisHeight());
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
    drawingEndCursor.set(drawingStartCursor.x(),drawingStartCursor.y()+M->MarkSize);
}

void GraphLayout::initYAxisMarks(){
    initOrigin();
    drawingEndCursor.set(drawingStartCursor.x()-M->MarkSize,drawingStartCursor.y());
}

void GraphLayout::initXAxisMarkEmphasis(){
    initOrigin();
    drawingEndCursor.set(drawingStartCursor.x(),drawingStartCursor.y()+M->MarkSize*2);
}

void GraphLayout::initYAxisMarkEmphasis(){
    initOrigin();
    drawingEndCursor.set(drawingStartCursor.x()-M->MarkSize*2,drawingStartCursor.y());
}

void GraphLayout::initXAxisNumbers(){
    drawingStartCursor.set(M->marginSize+M->yAxisWidth(),M->Size.height()-M->marginSize);
}

void GraphLayout::initYAxisNumbers(){
    drawingStartCursor.set(M->marginSize+M->yAxisWidth()/2,M->Size.height()- M->marginSize - M->xAxisHeight());
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
