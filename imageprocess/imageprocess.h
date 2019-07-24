#ifndef IMAGEPROCESS_H
#define IMAGEPROCESS_H

#include "ui_imageprocess.h"
#include <QtWidgets/QMainWindow>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>
#include <QPixmap>
#include<QSlider>
#include <QImage>
#include<QLabel>
#include <QDebug>
#include "M2Q.h"
using namespace cv;
using namespace std;
class imageprocess : public QMainWindow
{
	Q_OBJECT

public:
	imageprocess(QWidget *parent = 0);
	~imageprocess();

private:
	Ui::imageprocessClass ui;
	Mat image_M;//������ɫ�ռ�ΪBGR��ͼƬ
	QImage image_Q;//������ɫ�ռ�ΪRGB��ͼƬ
	int width_;//����ͼƬ���
	int height_;//����ͼƬ�߶�
	int brightness_;//��������ֵ�м����
	int contrast_;//����Աȶ�ֵ�м����
	int threshold_;//������ֵ�м����
	Mat image_brightness_contrast;//����ı����Ȼ�ԱȶȺ��ͼƬ
	Mat image_M_;//����image_M���м����(�ı����ȶԱȶ�ʱ)
	Mat image_M_T;//����image_M���м�������ı���ֵʱ��
	Mat image_M_I;//����image_M���м��������ͼƬʱ��
	int flags_brightness;//�ı����ȱ�־
	int flags_contrast;//�ı�Աȶȱ�־
	int flags_threhold;//�ı���ֵ��־
	QLabel *lableGet;//��ʾ��ȡ����ͼƬ
	QLabel *lableShow;//��ʾ������ͼƬ
	QLabel *lableWidth;//��ʾͼƬ���
	QLabel *lableHight;//��ʾͼƬ�߶�
	QLabel *lableRoot;//��ʾͼƬ·��
	QSlider *sliderForBright;//���ȵ��ڻ�����
	QSlider *sliderForContrast;//�Աȶȵ��ڻ�����
	QSlider *sliderForThreshold;//��ֵ���ڻ�����
public:
	void showGetImage();//��ʾ��ȡ����ͼƬ
	void showProImage();//��ʾ������ͼƬ
	void commenChannel(const int &channel,const int &channel_b,const int &channel_g,const int &channel_r,const Mat&img,const char *winTitle);//ͨ��ֱ��ͼ
	void sliderForBrightInit();//���Ȼ�������ʼ��
	void sliderForContrastInit();//�ԱȶȻ�������ʼ��
	void sliderForThresholdInit();//��ֵ��������ʼ��
	void getImageInformation();//��ȡͼƬ����
private slots:
	void getAndShowImage();//��ͼƬ����ʾ
	void canny_();//Canny��Ե���
	void sobel_();//Sobel��Ե���
	void laplacian_();//Laplacian��Ե���
	void erode_();//��ʴ
	void dilate_();//����
	void boxFilter_();//�����˲�
	void blur_();//��ֵ�˲�
	void GaussianBlur_();//��˹�˲�
	void medianBlur_();//��ֵ�˲�
	void bilateralFilter_();//˫���˲�
	void r_(const int &channel=0,const int &channel_b=0,const int &channel_g=0,const int &channel_r=255);//rͨ��ֱ��ͼ
	void g_(const int &channel=1,const int &channel_b=0,const int &channel_g=255,const int &channel_r=0);//gͨ��ֱ��ͼ
	void b_(const int &channel=2,const int &channel_b=255,const int &channel_g=0,const int &channel_r=0);//bͨ��ֱ��ͼ
	void gray_(const int &channel=0,const int &channel_b=125,const int &channel_g=125,const int &channel_r=125);//�Ҷ�ֱ��ͼ
	void changeBrightness(int brightness);//�ı����ȶ�
	void changeContrast(int contrast);//�ı�Աȶ�
	void changeThreshold(int threshold);//�ı���ֵ
	void faceDetect();//�������
	void reset();//���ò���
};

#endif // IMAGEPROCESS_H
