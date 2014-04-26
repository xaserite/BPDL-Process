#include <QtGui/QApplication>

#include "graphplot.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    GraphPlot G(QSize(800,320));
    GraphCurve C("test");
    G.addGraphCurve(&C);
    G.appendToGraphCurve(QPointF(50,75),"test");
    G.appendToGraphCurve(QPointF(50,50),"test");
    G.appendToGraphCurve(QPointF(75,50),"test");
    G.appendToGraphCurve(QPointF(75,75),"test");
    G.show();
    return a.exec();
}

