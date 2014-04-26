#ifndef GRAPHPLOT_H
#define GRAPHPLOT_H

#include <vector>
#include <QWidget>
#include <QPaintEvent>
#include <QtGlobal>

#include "graphcurve.h"
#include "graphlayout.h"
#include "graphlayoutmetrics.h"
#include "graphcurvedrawer.h"

class GraphPlot : public QWidget
{
    Q_OBJECT
public:
    explicit GraphPlot(QSize size, QWidget *parent = 0);

    void addGraphCurve(GraphCurve *Curve);
    void appendToGraphCurve(QPointF point,QString label);
    void appendToGraphCurve(QPointFVec points,QString label);
    void appendToGraphCurve(QVector<double> x,QVector<double> y,QString label);

protected:
    void paintEvent(QPaintEvent *event);
    
public slots:
    void updateGraphPlot();

private:
    QList<GraphCurve*> graphList;
    GraphCurve *GraphCursor;
    QPainter *painter;
    GraphLayout *Layout;
    GraphCurveDrawer *curveDrawer;

    bool containsPlotData();
    bool containsGraphCurve(QString label);
    void setGraphCursor(QString label);
    double xRangeInUnits();
    double yRangeInUnits();

    void drawGraphList();
};

#endif // GRAPHPLOT_H
