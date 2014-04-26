#include "graphcurve.h"
#include "helper.h"

GraphCurve::GraphCurve(QString label){
    Label = label;
}

GraphCurve::GraphCurve(QPointFVec Coords, QString label){
    Coordinates = Coords;
    Label = label;
}

GraphCurve::GraphCurve(std::vector<double> xPoint, std:: vector<double> yPoint, QString label){
    Label = label;
    extractCoordinates(xPoint,yPoint);
}

QPointFVec GraphCurve::getCoordinates(){
    return Coordinates;
}

QString GraphCurve::getLabel(){
    return Label;
}

double GraphCurve::xPointMax(){
    double xMax = 0;
    foreach(QPointF point,Coordinates)
        xMax = helper::takeGreater(xMax, point.x());
    return xMax;
}

double GraphCurve::yPointMax(){
    double yMax = 0;
    foreach(QPointF point,Coordinates)
        yMax = helper::takeGreater(yMax, point.y());
    return yMax;
}

void GraphCurve::appendQPointF(QPointF point){
    Coordinates.push_back(point);
}

void GraphCurve::appendQPointFs(QPointFVec points){
    foreach(QPointF point,points)
        appendQPointF(point);
}

bool GraphCurve::hasLabel(QString label){
    return (label == getLabel()) ? true : false;
}

void GraphCurve::extractCoordinates(std::vector<double> xPoint, std:: vector<double> yPoint){
    if (helper::areSameLength(xPoint,yPoint))
        for(size_t index = 0;index<xPoint.size();index++)
            extractSingleCoordinate(index, xPoint, yPoint);
}

void GraphCurve::extractSingleCoordinate(size_t index, std::vector<double> xPoint, std:: vector<double> yPoint){
    QPointF point(xPoint[index],yPoint[index]);
    appendQPointF(point);
}
