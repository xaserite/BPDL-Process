#ifndef GRAPHLAYOUT_H
#define GRAPHLAYOUT_H

#include <QWidget>
#include <QWidget>
#include <QPaintEvent>
#include <QtGlobal>

#include "drawingcursor.h"
#include "graphlayoutmetrics.h"

class GraphLayout
{
public:    
    explicit GraphLayout(GraphLayoutMetrics *D,QPainter *pt);
    void updateGraphLayout(QPointF Range);
    void drawLayout();
    
signals:
    
public slots:

private:
    QPainter *painter;
    GraphLayoutMetrics *M;
    QString xlabel;
    QString ylabel;

    drawingCursor drawingStartCursor;
    drawingCursor drawingEndCursor;
    void drawAxes();
    void drawMesh();
    void drawMarks();
    void drawNumbers();

    void drawXAxis();
    void drawYAxis();
    void drawXMesh();
    void drawYMesh();
    void drawXMeshSingleLine();
    void drawYMeshSingleLine();
    void drawXAxisMarks();
    void drawYAxisMarks();
    void drawXAxisMarkEmphasis();
    void drawYAxisMarkEmphasis();
    void drawXAxisNumbers();
    void drawYAxisNumbers();
    void drawXAxisArrow();
    void drawYAxisArrow();
    void drawXAxisSingleMark();
    void drawYAxisSingleMark();
    void drawXAxisSingleEmphasisedMark();
    void drawYAxisSingleEmphasisedMark();
    void drawXAxisSingleNumber(double number);
    void drawYAxisSingleNumber(double number);
    void drawLine();
    void initOrigin();
    void initXAxis();
    void initYAxis();
    void initXAxisMarks();
    void initYAxisMarks();
    void initXAxisMarkEmphasis();
    void initYAxisMarkEmphasis();
    void initXAxisNumbers();
    void initYAxisNumbers();

    void initPenBlack();
    void initPenDotted();
    void initPenCoarse();
    void initPenWide();
};

#endif // GRAPHLAYOUT_H
