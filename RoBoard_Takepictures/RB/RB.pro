#-------------------------------------------------
#
# Project created by QtCreator 2013-03-08T18:26:07
#
#-------------------------------------------------

QT       += core gui

TARGET = RB
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH +=   C:\OpenCV\cv\include \
  C:\OpenCV\cvaux\include \
  C:\OpenCV\cxcore\include \
  C:\OpenCV\otherlibs\highgui
LIBS +=   C:\OpenCV\lib\cv.lib \
  C:\OpenCV\lib\cvaux.lib \
  C:\OpenCV\lib\cxcore.lib \
  C:\OpenCV\lib\highgui.lib \
  C:\OpenCV\lib\cvcam.lib
