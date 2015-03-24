#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "opencv.hpp"
#include <time.h>
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
    cvNamedWindow("Webcam");
    timer->start(2000);
    qDebug()<<"start";

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    while(true)
    {
        frame = cvQueryFrame(capture);
        key = cvWaitKey(50);
        if(!timer->isActive())
        {
            break;
            qDebug()<<"timer is unable";
        }
        else
        {
            if(key == 'c')       //按c拍照
            {
                sprintf(fileName, "C:\\picture\\Picture %d.jpg", ++count); //生成文件名
                cvSaveImage(fileName, frame);
                cvXorS(frame, cvScalarAll(255), frame);
                cvShowImage("Webcam",frame);
                cvWaitKey(200);
            }
            else
            {
                cvShowImage("Webcam",frame);
            }
        }
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    timer->stop();
    cvReleaseCapture(&capture);
    cvDestroyWindow("Webcam");
    close();

}
void MainWindow::takeapicture()
{
    frame = cvQueryFrame(capture);
    //cvShowImage("Webcam",frame);
    sprintf(fileName, "C:\\picture\\Picture %d.jpg", ++count); //生成文件名
    cvSaveImage(fileName, frame);
    cvWaitKey(200);
    qDebug()<<"PICTURE";
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    timer->start(ui->verticalSlider->value());
}
