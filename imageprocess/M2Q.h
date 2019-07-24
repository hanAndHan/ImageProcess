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
	/***ʹ�÷�ʽ***/
	/*��Imagin.cpp*/
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
		QImage qImg2=qImg.copy();//��ȸ���
		if(cvImg.channels()==3)
		cvtColor(cvImg,cvImg,CV_RGB2BGR);
		return qImg2;//���ø��ƹ��캯������һ����������
	}
	/********************************ʹ�÷�ʽ*******************************/
	/*��qt�����н�һ��Mat��ĳ�Ա������������this��Ϊ������������ĺ�������*/
	static QImage getQImage(QWidget *parent,Mat &cvImg)
	{
		QString fileName = QFileDialog::getOpenFileName(parent,"Open Image",".","Image File(*.png *.jpg *.jpeg *.bmp)");  
		cvImg=imread(fileName.toLocal8Bit().data());
		return Mat2QImage(cvImg);
	}
	
};

#endif // M2Q_H
