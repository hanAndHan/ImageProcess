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
	Mat image_M;//保存颜色空间为BGR的图片
	QImage image_Q;//保存颜色空间为RGB的图片
	int width_;//保存图片宽度
	int height_;//保存图片高度
	int brightness_;//保存亮度值中间变量
	int contrast_;//保存对比度值中间变量
	int threshold_;//保存阈值中间变量
	Mat image_brightness_contrast;//保存改变亮度或对比度后的图片
	Mat image_M_;//保存image_M的中间变量(改变亮度对比度时)
	Mat image_M_T;//保存image_M的中间变量（改变阈值时）
	Mat image_M_I;//保存image_M的中间变量（打开图片时）
	int flags_brightness;//改变亮度标志
	int flags_contrast;//改变对比度标志
	int flags_threhold;//改变阈值标志
	QLabel *lableGet;//显示读取到的图片
	QLabel *lableShow;//显示处理后的图片
	QLabel *lableWidth;//显示图片宽度
	QLabel *lableHight;//显示图片高度
	QLabel *lableRoot;//显示图片路径
	QSlider *sliderForBright;//亮度调节滑动条
	QSlider *sliderForContrast;//对比度调节滑动条
	QSlider *sliderForThreshold;//阈值调节滑动条
public:
	void showGetImage();//显示读取到的图片
	void showProImage();//显示处理后的图片
	void commenChannel(const int &channel,const int &channel_b,const int &channel_g,const int &channel_r,const Mat&img,const char *winTitle);//通用直方图
	void sliderForBrightInit();//亮度滑动条初始化
	void sliderForContrastInit();//对比度滑动条初始化
	void sliderForThresholdInit();//阈值滑动条初始化
	void getImageInformation();//获取图片长宽
private slots:
	void getAndShowImage();//打开图片并显示
	void canny_();//Canny边缘检测
	void sobel_();//Sobel边缘检测
	void laplacian_();//Laplacian边缘检测
	void erode_();//腐蚀
	void dilate_();//膨胀
	void boxFilter_();//方框滤波
	void blur_();//均值滤波
	void GaussianBlur_();//高斯滤波
	void medianBlur_();//中值滤波
	void bilateralFilter_();//双边滤波
	void r_(const int &channel=0,const int &channel_b=0,const int &channel_g=0,const int &channel_r=255);//r通道直方图
	void g_(const int &channel=1,const int &channel_b=0,const int &channel_g=255,const int &channel_r=0);//g通道直方图
	void b_(const int &channel=2,const int &channel_b=255,const int &channel_g=0,const int &channel_r=0);//b通道直方图
	void gray_(const int &channel=0,const int &channel_b=125,const int &channel_g=125,const int &channel_r=125);//灰度直方图
	void changeBrightness(int brightness);//改变亮度度
	void changeContrast(int contrast);//改变对比度
	void changeThreshold(int threshold);//改变阈值
	void faceDetect();//人脸检测
	void reset();//重置参数
};

#endif // IMAGEPROCESS_H
