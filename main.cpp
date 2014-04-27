#include <QtGui/QApplication>

#include "graphplot.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    GraphPlot G(QSize(800,320));
    GraphCurve C("test");
    G.addGraphCurve(&C);
    G.appendToGraphCurve(QPointF(0,40),"test");
    G.appendToGraphCurve(QPointF(10,22),"test");
    G.appendToGraphCurve(QPointF(20,37),"test");
    G.appendToGraphCurve(QPointF(30,13),"test");
    G.appendToGraphCurve(QPointF(40,49),"test");
    G.appendToGraphCurve(QPointF(50,33),"test");
    G.appendToGraphCurve(QPointF(60,45),"test");
    G.show();
    return a.exec();
}

