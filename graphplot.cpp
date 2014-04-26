#include "graphplot.h"
#include "graphcurve.h"

#include <QPen>
#include <QPainter>

GraphPlot::GraphPlot(QSize size, QWidget *parent) :
    QWidget(parent)
{
    setMinimumSize(size);
    setMaximumSize(size);
    painter = new QPainter();
    GraphLayoutMetrics *D = new GraphLayoutMetrics(size);
    Layout = new GraphLayout(D,painter);
    curveDrawer = new GraphCurveDrawer(D,painter);
}

void GraphPlot::addGraphCurve(GraphCurve *Curve){
    if (!containsGraphCurve(Curve->getLabel()))
        graphList.append(Curve);
}

void GraphPlot::appendToGraphCurve(QPointF point, QString label){
    if (!containsGraphCurve(label)) return;
        setGraphCursor(label);
        GraphCursor->appendQPointF(point);
}

void GraphPlot::appendToGraphCurve(QPointFVec points,QString label){
    if (!containsGraphCurve(label)) return;
        setGraphCursor(label);
        GraphCursor->appendQPointFs(points);
}

void GraphPlot::paintEvent(QPaintEvent *event){
    QWidget::paintEvent(event);
    painter->begin(this);
    Layout->drawLayout();
    drawGraphList();
    painter->end();
}

void GraphPlot::updateGraphPlot(){
    QPointF Range = QPointF(xRangeInUnits(),yRangeInUnits());
    Layout->updateGraphLayout(Range);
}

void GraphPlot::setGraphCursor(QString label){
    foreach(GraphCurve *graph, graphList)
        if (graph->hasLabel(label))
            GraphCursor = graph;
}

bool GraphPlot::containsPlotData(){
    return (graphList.count()>0) ? true : false;
}

bool GraphPlot::containsGraphCurve(QString label){
    foreach(GraphCurve *graph,graphList)
        if (graph->hasLabel(label)) return true;
    return false;
}

double GraphPlot::xRangeInUnits(){
    if (!containsPlotData()) return 100;
    double maxXPoint = 0;
    foreach(GraphCurve *G,graphList) maxXPoint = (G->xPointMax()>maxXPoint) ? G->yPointMax() : maxXPoint;
    return maxXPoint;
}

double GraphPlot::yRangeInUnits(){
    if (!containsPlotData()) return 100;
    double maxYPoint = 0;
    foreach(GraphCurve *G,graphList) maxYPoint = (G->yPointMax()>maxYPoint) ? G->yPointMax() : maxYPoint;
    return maxYPoint;
}

void GraphPlot::drawGraphList(){
    foreach(GraphCurve *curve,graphList)
        curveDrawer->draw(*curve);
}
