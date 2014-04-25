#ifndef GRAPHPLOT_H
#define GRAPHPLOT_H

#include <vector>
#include <QWidget>
#include <QPaintEvent>
#include <QtGlobal>

#include "graphcurve.h"
#include "graphlayout.h"
#include "graphlayoutmetrics.h"

class GraphPlot : public QWidget
{
    Q_OBJECT
public:
    explicit GraphPlot(QSize size, QWidget *parent = 0);

    void addGraphCurve(GraphCurve *Curve);
    void appendToGraphCurve(QPointF point,QString label);
    void appendToGraphCurve(QPointFVec points,QString label);

protected:
    void paintEvent(QPaintEvent *event);
    
public slots:
    void updateGraphPlot();

private:
    GraphCurveList graphList;
    GraphCurve *GraphCursor;
    QPainter *painter;
    GraphLayout *Layout;

    bool containsPlotData();
    bool containsGraphCurve(QString label);
    void setGraphCursor(QString label);
    double xRangeInUnits();
    double yRangeInUnits();
};

#endif // GRAPHPLOT_H
