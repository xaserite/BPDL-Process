#-------------------------------------------------
#
# Project created by QtCreator 2014-03-14T10:50:31
#
#-------------------------------------------------

QT       += core gui
#CONFIG += c++11

QMAKE_CXXFLAGS += -std=c++11

TARGET = SMPP
TEMPLATE = app

SOURCES += main.cpp\
    graphplot.cpp \
    graphcurve.cpp \
    drawingcursor.cpp \
    window.cpp \
    graphlayout.cpp \
    graphlayoutmetrics.cpp

HEADERS  += \
    graphplot.h \
    graphcurve.h \
    helper.h \
    drawingcursor.h \
    window.h \
    graphlayout.h \
    graphlayoutmetrics.h

FORMS    +=
