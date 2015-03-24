#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <cv.h>
#include <highgui.h>
#include <cxcore.h>
#include <cvaux.h>
#include <QDebug>
#include "QTimer"

CvCapture *capture;
IplImage *frame;
char key;
char fileName[100];
int count = 0;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(takeapicture()));
    capture =cvCaptureFromCAM(0) ;
    timer->start(2000);
    qDebug()<<"start";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    close();
    cvReleaseCapture(&capture);
    cvDestroyWindow("Webcam");
}
void MainWindow::takeapicture()
{

    frame = cvQueryFrame(capture);
    sprintf(fileName, "C:\\picture\\Picture %d.jpg", ++count);
    cvSaveImage(fileName, frame);
    cvWaitKey(200);
    qDebug()<<"PICTURE";
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    timer->start(ui->verticalSlider->value());
}
