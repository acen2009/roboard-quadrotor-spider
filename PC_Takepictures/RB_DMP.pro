#-------------------------------------------------
#
# Project created by QtCreator 2013-03-18T19:39:28
#
#-------------------------------------------------

QT       += core gui

TARGET = RB_DMP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += C:/Users/William/Desktop/opencv240/include

OpenCV_Libd = C:/Users/William/Desktop/openCV240/lib
OpenCV_Lib = C:/Users/William/Desktop/openCV240/lib


Release: LIBS +=  $$OpenCV_Lib/opencv_highgui240.lib\
                                $$OpenCV_Lib/opencv_calib3d240.lib\
                                $$OpenCV_Lib/opencv_contrib240.lib\
                                $$OpenCV_Lib/opencv_core240.lib\
                                $$OpenCV_Lib/opencv_features2d240.lib\
                                $$OpenCV_Lib/opencv_flann240.lib\
                                $$OpenCV_Lib/opencv_gpu240.lib\
                                $$OpenCV_Lib/opencv_imgproc240.lib\
                                $$OpenCV_Lib/opencv_legacy240.lib\
                                $$OpenCV_Lib/opencv_ml240.lib\
                                $$OpenCV_Lib/opencv_objdetect240.lib\
                                $$OpenCV_Lib/opencv_ts240.lib\
                                $$OpenCV_Lib/opencv_video240.lib\
                                $$OpenCV_Lib/tbb.lib
