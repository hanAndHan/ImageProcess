#ifndef M2Q_H
#define M2Q_H

#include <QImage>
#include <QFileDialog>
#include <opencv2\imgproc\types_c.h> 
#include <opencv2/opencv.hpp>
#include <string>
using namespace cv;

class M2Q
{
	
public:
	/***使用方式***/
	/*见Imagin.cpp*/
	static QImage Mat2QImage(Mat cvImg)
	{
		QImage qImg;
		if(cvImg.channels()==3)                             //3 channels color image
		{

			cvtColor(cvImg,cvImg,CV_BGR2RGB);
			qImg =QImage((const unsigned char*)(cvImg.data),
				cvImg.cols, cvImg.rows,
				cvImg.cols*cvImg.channels(),
				QImage::Format_RGB888);
		}
		else if(cvImg.channels()==1)                    //grayscale image
		{
			qImg =QImage((const unsigned char*)(cvImg.data),
				cvImg.cols,cvImg.rows,
				cvImg.cols*cvImg.channels(),
				QImage::Format_Indexed8);
		}
		else
		{
			qImg =QImage((const unsigned char*)(cvImg.data),
				cvImg.cols,cvImg.rows,
				cvImg.cols*cvImg.channels(),
				QImage::Format_RGB888);
		}
		QImage qImg2=qImg.copy();//深度复制
		if(cvImg.channels()==3)
		cvtColor(cvImg,cvImg,CV_RGB2BGR);
		return qImg2;//调用复制构造函数返回一个匿名对象
	}
	/********************************使用方式*******************************/
	/*在qt的类中建一个Mat类的成员变量，把它和this作为参数传进下面的函数就行*/
	static QImage getQImage(QWidget *parent,Mat &cvImg)
	{
		QString fileName = QFileDialog::getOpenFileName(parent,"Open Image",".","Image File(*.png *.jpg *.jpeg *.bmp)");  
		cvImg=imread(fileName.toLocal8Bit().data());
		return Mat2QImage(cvImg);
	}
	
};

#endif // M2Q_H
