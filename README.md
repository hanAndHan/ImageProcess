# ImageProcess
开发环境：vs2010 qt5.5.0 opencv3.0
## 1.总体框架
![](https://github.com/hanAndHan/ImageProcess/blob/master/img/框架.png)
## 2.界面
![](https://github.com/hanAndHan/ImageProcess/blob/master/img/界面.png)
## 3.代码构成
Header:	#include"imageprocess.h"</br>
Inherits:	QMainWindow</br>

Properties</br>
Mat image_M;//保存颜色空间为BGR的图片</br>
QImage image_Q;//保存颜色空间为RGB的图片</br>
int width_;//保存图片宽度</br>
int height_;//保存图片高度</br>
int brightness_;//保存亮度值中间变量</br>
int contrast_;//保存对比度值中间变量</br>
int threshold_;//保存阈值中间变量</br>
Mat image_brightness_contrast;//保存改变亮度或对比度后的图片</br>
Mat image_M_;//保存image_M的中间变量(改变亮度对比度时)</br>
Mat image_M_T;//保存image_M的中间变量（改变阈值时）</br>
Mat image_M_I;//保存image_M的中间变量（打开图片时）</br>
int flags_brightness;//改变亮度标志</br>
int flags_contrast;//改变对比度标志</br>
int flags_threhold;//改变阈值标志</br>
QLabel *lableGet;//显示读取到的图片</br>
QLabel *lableShow;//显示处理后的图片</br>
QLabel *lableWidth;//显示图片宽度</br>
QLabel *lableHight;//显示图片高度</br>
QLabel *lableRoot;//显示图片路径</br>
QSlider *sliderForBright;//亮度调节滑动条</br>
QSlider *sliderForContrast;//对比度调节滑动条</br>
QSlider *sliderForThreshold;//阈值调节滑动条</br>
Public Functions</br>
void showGetImage();//显示读取到的图片</br>
void showProImage();//显示处理后的图片</br>
void commenChannel(const int &channel,const int &channel_b,const int &channel_g,const int &channel_r,const Mat&img,const char *winTitle);//通用直方图</br>
void sliderForBrightInit();//亮度滑动条初始化</br>
void sliderForContrastInit();//对比度滑动条初始化</br>
void sliderForThresholdInit();//阈值滑动条初始化</br>
void getImageInformation();//获取图片长宽</br>

Private Slots</br>
void getAndShowImage();//打开图片并显示</br>
void canny_();//Canny边缘检测</br>
void sobel_();//Sobel边缘检测</br>
void laplacian_();//Laplacian边缘检测</br>
void erode_();//腐蚀</br>
void dilate_();//膨胀</br>
void boxFilter_();//方框滤波</br>
void blur_();//均值滤波</br>
void GaussianBlur_();//高斯滤波</br>
void medianBlur_();//中值滤波</br>
void bilateralFilter_();//双边滤波</br>
void r_(const int &channel=0,const int &channel_b=0,const int &channel_g=0,const int &channel_r=255);//r通道直方图</br>
void g_(const int &channel=1,const int &channel_b=0,const int &channel_g=255,const int &channel_r=0);//g通道直方图</br>
void b_(const int &channel=2,const int &channel_b=255,const int &channel_g=0,const int &channel_r=0);//b通道直方图</br>
void gray_(const int &channel=0,const int &channel_b=125,const int &channel_g=125,const int &channel_r=125);//灰度直方图</br>
void changeBrightness(int brightness);//改变亮度度</br>
void changeContrast(int contrast);//改变对比度</br>
void changeThreshold(int threshold);//改变阈值</br>
void faceDetect();//人脸检测</br>
void reset();//重置参数</br>
