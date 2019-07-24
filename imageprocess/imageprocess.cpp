#include "imageprocess.h"

imageprocess::imageprocess(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	lableGet=new QLabel();
	lableShow=new QLabel();
	ui.scrollArea->setWidget(lableGet);
	ui.scrollArea_2->setWidget(lableShow);

	lableHight=new QLabel();
	lableWidth=new QLabel();
	lableRoot=new QLabel();
	ui.statusBar->addWidget(lableWidth);
	ui.statusBar->addWidget(lableHight);
	ui.statusBar->addWidget(lableRoot);

	sliderForBright=new QSlider(this);
	sliderForBrightInit();
	sliderForContrast=new QSlider(this);
	sliderForContrastInit();
	sliderForThreshold=new QSlider(this);
	sliderForThresholdInit();

	brightness_=0;
	contrast_=100;
	threshold_=122;
	flags_brightness=0;
	flags_contrast=0;
	flags_threhold=0;
	connect(sliderForBright,SIGNAL(valueChanged(int)),this,SLOT(changeBrightness(int)));
	connect(sliderForContrast,SIGNAL(valueChanged(int)),this,SLOT(changeContrast(int)));
	connect(sliderForThreshold,SIGNAL(valueChanged(int)),this,SLOT(changeThreshold(int)));
	connect(ui.actionOpen,SIGNAL(triggered()),this,SLOT(getAndShowImage()));
	connect(ui.actionCanny,SIGNAL(triggered()),this,SLOT(canny_()));
	connect(ui.actionSobel,SIGNAL(triggered()),this,SLOT(sobel_()));
	connect(ui.actionLaplacian,SIGNAL(triggered()),this,SLOT(laplacian_()));
	connect(ui.actionDilate,SIGNAL(triggered()),this,SLOT(dilate_()));
	connect(ui.actionErode,SIGNAL(triggered()),this,SLOT(erode_()));
	connect(ui.actionR,SIGNAL(triggered()),this,SLOT(r_()));
	connect(ui.actionG,SIGNAL(triggered()),this,SLOT(g_()));
	connect(ui.actionB,SIGNAL(triggered()),this,SLOT(b_()));
	connect(ui.actionGry,SIGNAL(triggered()),this,SLOT(gray_()));
    connect(ui.actionReset,SIGNAL(triggered()),this,SLOT(reset()));
	connect(ui.actionBox,SIGNAL(triggered()),this,SLOT(boxFilter_()));
	connect(ui.actionMeans,SIGNAL(triggered()),this,SLOT(blur_()));
	connect(ui.actionGuass,SIGNAL(triggered()),this,SLOT(GaussianBlur_()));
	connect(ui.actionMidvalue,SIGNAL(triggered()),this,SLOT(medianBlur_()));
	connect(ui.actionDoubledge,SIGNAL(triggered()),this,SLOT(bilateralFilter_()));
	connect(ui.actionFacedetect,SIGNAL(triggered()),this,SLOT(faceDetect()));
}

imageprocess::~imageprocess()
{

}
//亮度滑动条初始化
void imageprocess::sliderForBrightInit()
{
	sliderForBright->setMaximumSize(QSize(100,50));
	sliderForBright->setOrientation(Qt::Horizontal);

	sliderForBright->setMinimum(-255);
	sliderForBright->setMaximum(255);
	sliderForBright->setValue(0);//一定要在设置最小值和最大值之后再设置当前值

	sliderForBright->setToolTip(QString::fromLocal8Bit("亮度"));
	ui.mainToolBar->addWidget(sliderForBright);
	ui.mainToolBar->addSeparator();
}
//对比度滑动条初始化
void imageprocess::sliderForContrastInit()
{
	sliderForContrast->setMaximumSize(QSize(100,50));
	sliderForContrast->setOrientation(Qt::Horizontal);
	
	sliderForContrast->setMinimum(0);
	sliderForContrast->setMaximum(200);
	sliderForContrast->setValue(100);//一定要在设置最小值和最大值之后再设置当前值

	sliderForContrast->setToolTip(QString::fromLocal8Bit("对比度"));
	ui.mainToolBar->addWidget(sliderForContrast);
	ui.mainToolBar->addSeparator();
}
//阈值滑动条初始化
void imageprocess::sliderForThresholdInit()
{
	sliderForThreshold->setMaximumSize(QSize(100,50));
	sliderForThreshold->setOrientation(Qt::Horizontal);

	sliderForThreshold->setMinimum(-1);
	sliderForThreshold->setMaximum(255);
    sliderForThreshold->setValue(122);//一定要在设置最小值和最大值之后再设置当前值

	sliderForThreshold->setToolTip(QString::fromLocal8Bit("阈值"));
	ui.mainToolBar->addWidget(sliderForThreshold);
	ui.mainToolBar->addSeparator();
}
//改变亮度度
void imageprocess::changeBrightness(int brightness)
{
	if(flags_brightness!=0)
	{
		/*if(image_M_.channels()==1)
			cvtColor(image_M_,image_M_,COLOR_GRAY2BGR);*/
		image_M=image_M_.clone();
	}
	brightness_=brightness;
	image_brightness_contrast=Mat::zeros(image_M.size(),image_M.type());
	for(int i = 0; i<image_M.rows; i++)
	{
		for(int j = 0; j<image_M.cols; j++)
		{
			image_brightness_contrast.at<Vec3b>(i, j)[0] = saturate_cast<uchar>(contrast_ * 0.01 * image_M.at<Vec3b>(i, j)[0] + brightness_);
			image_brightness_contrast.at<Vec3b>(i, j)[1] = saturate_cast<uchar>(contrast_ * 0.01 * image_M.at<Vec3b>(i, j)[1] + brightness_);
			image_brightness_contrast.at<Vec3b>(i, j)[2] = saturate_cast<uchar>(contrast_ * 0.01 * image_M.at<Vec3b>(i, j)[2] + brightness_);
		}
	}
	image_M_=image_M.clone();
	image_M=image_brightness_contrast.clone();
	image_Q=M2Q::Mat2QImage(image_M);//这一步会把image_M从BGR转为RGB
	showProImage();
	//cvtColor(image_M,image_M,COLOR_RGB2BGR);//重新转为BGR
	flags_brightness++;
	image_M_T=image_M.clone();//目的是在调节阈值的时候使image_M获得最新的值
}
//改变对比度
void imageprocess::changeContrast(int contrast)
{
	if(flags_contrast!=0)
	{
		/*if(image_M_.channels()==1)
			cvtColor(image_M_,image_M_,COLOR_GRAY2BGR);*/
		image_M=image_M_.clone();
	}	
	contrast_=contrast;
	image_brightness_contrast=Mat::zeros(image_M.size(),image_M.type());
	for(int i = 0; i<image_M.rows; i++)
	{
		for(int j = 0; j<image_M.cols; j++)
		{
			image_brightness_contrast.at<Vec3b>(i, j)[0] = saturate_cast<uchar>(contrast_ * 0.01 * image_M.at<Vec3b>(i, j)[0] + brightness_);
			image_brightness_contrast.at<Vec3b>(i, j)[1] = saturate_cast<uchar>(contrast_ * 0.01 * image_M.at<Vec3b>(i, j)[1] + brightness_);
			image_brightness_contrast.at<Vec3b>(i, j)[2] = saturate_cast<uchar>(contrast_ * 0.01 * image_M.at<Vec3b>(i, j)[2] + brightness_);
		}
	}
	image_M_=image_M.clone();
	image_M=image_brightness_contrast.clone();
	image_Q=M2Q::Mat2QImage(image_M);//这一步会把image_M从BGR转为RGB
	showProImage();
	//cvtColor(image_M,image_M,COLOR_RGB2BGR);//重新转为BGR
	flags_contrast++;
	image_M_T=image_M.clone();//目的是在调节阈值的时候使image_M获得最新的值
}

//改变阈值
void imageprocess::changeThreshold(int thresholds)
{
	threshold_=thresholds;
	if(flags_threhold!=0)
		image_M=image_M_T.clone();
	if(image_M.channels()==3)
		cvtColor(image_M,image_M,COLOR_BGR2GRAY);
	Mat image_m;
	image_M_T=image_M.clone();
	threshold(image_M, image_m, threshold_,255, THRESH_BINARY);
	image_M=image_m.clone();
	image_Q=M2Q::Mat2QImage(image_M);
	showProImage();
	cvtColor(image_M,image_M,COLOR_GRAY2BGR);//重新转为BGR
	flags_threhold++;
	image_M_=image_M.clone();//目的是在调节亮度和对比度的时候使image_M获得最新的值

	//if(flags_threhold!=0)
	//	image_M=image_M_.clone();
	//if(image_M.channels()==3)
	//	cvtColor(image_M,image_M,COLOR_BGR2GRAY);
	//Mat image_m;
	//image_M_=image_M.clone();
	//threshold(image_M, image_m, thresholds,255, THRESH_BINARY);
	//image_M=image_m.clone();
	//image_Q=M2Q::Mat2QImage(image_M);
	//showProImage();
	//cvtColor(image_M,image_M,COLOR_GRAY2BGR);//重新转为BGR
	//flags_threhold++;
}

//打开图片并显示
void imageprocess::getAndShowImage()
{
	QString fileName = QFileDialog::getOpenFileName(this,"Open Image",".","Image File(*.png *.jpg *.jpeg *.bmp)");
	if(fileName.isEmpty())
		return;
	image_M=imread(fileName.toLocal8Bit().data());

	getImageInformation();
	char str[100];
	sprintf(str,"宽度：%d",width_);
	lableHight->setText(QString::fromLocal8Bit(str));
	sprintf(str,"高度：%d",height_);
	lableWidth->setText(QString::fromLocal8Bit(str));
	QString str1=QString::fromLocal8Bit("位置：");
	lableRoot->setText(str1.append(fileName));

	image_M_I=image_M.clone();
	image_M_=image_M.clone();//目的是在调节亮度和对比度的时候使image_M获得最新的值
	image_M_T=image_M.clone();//目的是在调节阈值的时候使image_M获得最新的值
	image_Q=M2Q::Mat2QImage(image_M);//这一步会把image_M从BGR转为RGB
	showGetImage();
	showProImage();
	//cvtColor(image_M,image_M,COLOR_RGB2BGR);//重新转为BGR

	ui.mainToolBar->setEnabled(true);
	ui.menu_edge->setEnabled(true);
	ui.menu_histogram->setEnabled(true);
	ui.menu_line->setEnabled(true);
	ui.menu_nonline->setEnabled(true);
	ui.actionFacedetect->setEnabled(true);
	ui.actionErode->setEnabled(true);
	ui.actionDilate->setEnabled(true);

}
//显示读取到的图片
void imageprocess::showGetImage()
{
	//ui.label->setScaledContents(true);
	
	ui.label->setGeometry(80,30,image_Q.width()/10,image_Q.height()/10);
	ui.label->setPixmap(QPixmap::fromImage(image_Q.scaled(image_Q.width()/10,image_Q.height()/10))); 
	//ui.label->setPixmap(QPixmap::fromImage(image_Q.scaled(10,20))); 
	qDebug()<<image_Q.height();
	qDebug()<<image_Q.width();
	//ui.label->setPixmap(QPixmap::fromImage(image_Q.scaled(ui.label->size()))); 
	//没用//ui.label->setScaledContents(true);
	//没用//ui.label->setPixmap(QPixmap::fromImage(image_Q)); 
	//没用//ui.label->resize(ui.label->pixmap()->size()); 
	
	lableShow->clear();
	lableGet->setPixmap(QPixmap::fromImage(image_Q)); 
	lableGet->resize(QSize(image_Q.width(),image_Q.height()));
		
}
//显示处理后的图片
void imageprocess::showProImage()
{
	lableShow->setPixmap(QPixmap::fromImage(image_Q));  
	lableShow->resize(QSize(image_Q.width(),image_Q.height()));
}
//Canny边缘检测
void imageprocess::canny_()
{
	if(image_M.channels()==3)
		cvtColor(image_M,image_M,COLOR_BGR2GRAY);
	Canny(image_M, image_M, 40, 90);//30表示低阈值，80表示高阈值，推荐高低阈值比值在2:1到3:1之间
	image_Q=M2Q::Mat2QImage(image_M);
	showProImage();
	cvtColor(image_M,image_M,COLOR_GRAY2BGR);//重新转为BGR
	image_M_=image_M.clone();//目的是在调节亮度和对比度的时候使image_M获得最新的值
	image_M_T=image_M.clone();//目的是在调节阈值的时候使image_M获得最新的值
}
//Sobel边缘检测
void imageprocess::sobel_()
{
	if(image_M.channels()==3)
		cvtColor(image_M,image_M,COLOR_BGR2GRAY);
	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y, dst;
	Sobel(image_M, grad_x, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);//处理x方向
	convertScaleAbs(grad_x, abs_grad_x);

	Sobel(image_M, grad_y, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);//处理y方向
	convertScaleAbs(grad_y, abs_grad_y);

	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, image_M);

	image_Q=M2Q::Mat2QImage(image_M);
	showProImage();
	cvtColor(image_M,image_M,COLOR_GRAY2BGR);//重新转为BGR
	image_M_=image_M.clone();//目的是在调节亮度和对比度的时候使image_M获得最新的值
	image_M_T=image_M.clone();//目的是在调节阈值的时候使image_M获得最新的值
}
//Laplacian边缘检测
void imageprocess::laplacian_()
{
	if(image_M.channels()==3)
		cvtColor(image_M,image_M,COLOR_BGR2GRAY);
	Mat dst;
	Laplacian(image_M, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(dst, image_M);

	image_Q=M2Q::Mat2QImage(image_M);
	showProImage();
	cvtColor(image_M,image_M,COLOR_GRAY2BGR);//重新转为BGR
	image_M_=image_M.clone();//目的是在调节亮度和对比度的时候使image_M获得最新的值
	image_M_T=image_M.clone();//目的是在调节阈值的时候使image_M获得最新的值
}
//腐蚀
void imageprocess::erode_()
{
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(5, 5),Point(-1,-1));
	//获得指定的核，包含核的形状和大小，MORPH_ELLIPSE指的是椭圆，这里的Point(-1,-1)是核的内部的中心位置
	erode(image_M, image_M, element, Point(-1, -1), 1);//腐蚀操作，最后一个1是腐蚀的次数，这个Point(-1，-1)好像没什么用
	image_Q=M2Q::Mat2QImage(image_M);//这一步会把image_M从BGR转为RGB
	showProImage();
	//cvtColor(image_M,image_M,COLOR_RGB2BGR);//重新转为BGR
	image_M_=image_M.clone();//目的是在调节亮度和对比度的时候使image_M获得最新的值
	image_M_T=image_M.clone();//目的是在调节阈值的时候使image_M获得最新的值
}
//膨胀
void imageprocess::dilate_()
{
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(5, 5),Point(-1,-1));
	//获得指定的核，包含核的形状和大小，MORPH_ELLIPSE指的是椭圆，这里的Point(-1,-1)是核的内部的中心位置
	dilate(image_M,image_M, element, Point(-1, -1), 1);//膨胀操作，最后一个1是膨胀的次数
	image_Q=M2Q::Mat2QImage(image_M);//这一步会把image_M从BGR转为RGB
	showProImage();
	//cvtColor(image_M,image_M,COLOR_RGB2BGR);//重新转为BGR
	image_M_=image_M.clone();//目的是在调节亮度和对比度的时候使image_M获得最新的值
	image_M_T=image_M.clone();//目的是在调节阈值的时候使image_M获得最新的值
}
//通用直方图
void imageprocess::commenChannel(const int &channel,const int &channel_b,const int &channel_g,const int &channel_r,const Mat&img,const char *winTitle)
{
	int nimg = 1;  //img中存放图像的个数
	int dims = 1;  //需要统计的特征数目(只统计灰度值)
	int channels =channel; //通道的索引
	MatND dstHist;  //定义存储直方图纵坐标的变量，比如横坐标为22，纵坐标为333的点表示灰度为22的点有333个
	int bins = 256; //直方图的横坐标刻度个数 0到255一共256个刻度
	float hranges[] = {0, 256};  //范围[0,256)注意是最大值加1
	int maxHeight=200;//最大高度
	const float* ranges[] = {hranges};

	calcHist(&img, nimg, &channels, Mat(), dstHist, dims, &bins, ranges);//计算直方图

	Mat dstImg(bins, bins*3, CV_8UC3, Scalar(240,240,240));  //定义显示直方图的输出图像
	double maxValue ;//保存直方图纵坐标最大值
	minMaxLoc(dstHist, 0, &maxValue, 0, 0);
	int scale = 3;//间距
	for(int i=0; i<256; i++)
	{
		float binValue = dstHist.at<float>(i);
		int realValue;
		if(maxValue==0)
			realValue=0;
		else
			realValue= saturate_cast<int>(binValue*maxHeight/maxValue);  //归一化数据，并向下取整
		line(dstImg, Point(i*scale, bins), Point(i*scale, bins-realValue), Scalar(channel_b, channel_g, channel_r), 1, 8);
	}
	imshow(winTitle,dstImg);
}
//r通道直方图
void imageprocess::r_(const int &channel,const int &channel_b,const int &channel_g,const int &channel_r)
{
	if(image_M.channels()==1)
		QMessageBox::warning
		(
		this, 
		QString::fromLocal8Bit("警告"),
		QString::fromLocal8Bit("当前处理的图片是单通道，请使用灰度直方图")
		);  
	else
		commenChannel(channel,channel_b,channel_g,channel_r,image_M,"R通道直方图");
}
//g通道直方图
void imageprocess::g_(const int &channel,const int &channel_b,const int &channel_g,const int &channel_r)
{	
	if(image_M.channels()==1)
		QMessageBox::warning
		(
		this, 
		QString::fromLocal8Bit("警告"),
		QString::fromLocal8Bit("当前处理的图片是单通道，请使用灰度直方图")
		);  
	else
	commenChannel(channel,channel_b,channel_g,channel_r,image_M,"G通道直方图");
}
//b通道直方图
void imageprocess::b_(const int &channel,const int &channel_b,const int &channel_g,const int &channel_r)
{
	if(image_M.channels()==1)
		QMessageBox::warning
		(
		this, 
		QString::fromLocal8Bit("警告"),
		QString::fromLocal8Bit("当前处理的图片是单通道，请使用灰度直方图")
		);  
	else
	commenChannel(channel,channel_b,channel_g,channel_r,image_M,"B通道直方图");
}
//灰度直方图
void imageprocess::gray_(const int &channel,const int &channel_b,const int &channel_g,const int &channel_r)
{
	
	Mat image_m=image_M.clone();
	if(image_m.channels()!=1)
	cvtColor(image_m,image_m,CV_BGR2GRAY);
	commenChannel(channel,channel_b,channel_g,channel_r,image_m,"灰度直方图");
}
//重置参数
void imageprocess::reset()
{
	image_M=image_M_I.clone();
	image_Q=M2Q::Mat2QImage(image_M);//这一步会把image_M从BGR转为RGB
	showProImage();
	//cvtColor(image_M,image_M,COLOR_RGB2BGR);//重新转为BGR

	/*sliderForBright->setSliderPosition(0);
	sliderForContrast->setSliderPosition(100);
	sliderForThreshold->setSliderPosition(122);*/

	brightness_=0;
	contrast_=100;
	threshold_=100;
	flags_brightness=0;
	flags_contrast=0;
	flags_threhold=0;
}
//方框滤波
void imageprocess::boxFilter_()
{
	boxFilter(image_M, image_M, -1, Size(3, 3), Point(-1, -1), false);  //方框滤波器
	image_Q=M2Q::Mat2QImage(image_M);//这一步会把image_M从BGR转为RGB
	showProImage();
	//cvtColor(image_M,image_M,COLOR_RGB2BGR);//重新转为BGR
	image_M_=image_M.clone();//目的是在调节亮度和对比度的时候使image_M获得最新的值
	image_M_T=image_M.clone();//目的是在调节阈值的时候使image_M获得最新的值
}
//均值滤波
void imageprocess::blur_()
{
	blur(image_M, image_M, Size(3,3));  //均值滤波
	image_Q=M2Q::Mat2QImage(image_M);//这一步会把image_M从BGR转为RGB
	showProImage();
	//cvtColor(image_M,image_M,COLOR_RGB2BGR);//重新转为BGR
	image_M_=image_M.clone();//目的是在调节亮度和对比度的时候使image_M获得最新的值
	image_M_T=image_M.clone();//目的是在调节阈值的时候使image_M获得最新的值
}
//高斯滤波
void imageprocess::GaussianBlur_()
{
	GaussianBlur(image_M, image_M, Size(3,3), 0,0);//高斯滤波，没看懂系数怎么设置
	image_Q=M2Q::Mat2QImage(image_M);//这一步会把image_M从BGR转为RGB
	showProImage();
	//cvtColor(image_M,image_M,COLOR_RGB2BGR);//重新转为BGR
	image_M_=image_M.clone();//目的是在调节亮度和对比度的时候使image_M获得最新的值
	image_M_T=image_M.clone();//目的是在调节阈值的时候使image_M获得最新的值
}
//中值滤波
void imageprocess::medianBlur_()
{
	medianBlur(image_M, image_M, 5);//中值滤波
	image_Q=M2Q::Mat2QImage(image_M);//这一步会把image_M从BGR转为RGB
	showProImage();
	//cvtColor(image_M,image_M,COLOR_RGB2BGR);//重新转为BGR
	image_M_=image_M.clone();//目的是在调节亮度和对比度的时候使image_M获得最新的值
	image_M_T=image_M.clone();//目的是在调节阈值的时候使image_M获得最新的值
}
//双边滤波
void imageprocess::bilateralFilter_()
{
	Mat image_m;
	bilateralFilter(image_M, image_m, 5, 20.0, 10.0);//双边滤波
	image_M=image_m.clone();
	image_Q=M2Q::Mat2QImage(image_M);//这一步会把image_M从BGR转为RGB
	showProImage();
//	cvtColor(image_M,image_M,COLOR_RGB2BGR);//重新转为BGR
	image_M_=image_M.clone();//目的是在调节亮度和对比度的时候使image_M获得最新的值
	image_M_T=image_M.clone();//目的是在调节阈值的时候使image_M获得最新的值
}
//人脸检测
void imageprocess::faceDetect()
{
	string xmlPath="haarcascade_frontalface_default.xml"; 
	CascadeClassifier ccf;   //创建分类器对象
	   
	if(!ccf.load(xmlPath))   //加载训练文件
	{
		cout<<"不能加载指定的xml文件"<<endl;
		return ;
	}
	vector<Rect> faces;  //创建一个容器保存检测出来的脸
	Mat gray;
	Mat image_m=image_M.clone();
	cvtColor(image_m,gray,COLOR_BGR2GRAY); //转换成灰度图，因为harr特征从灰度图中提取
	equalizeHist(gray,gray);  //直方图均衡行
	ccf.detectMultiScale(gray,faces,1.1,3,0,Size(10,10),Size(400,400)); //检测人脸
	for(vector<Rect>::const_iterator iter=faces.begin();iter!=faces.end();iter++)
	{
		rectangle(image_m,*iter,Scalar(108,226,108),2,8); //画出脸部矩形
	}
	image_Q=M2Q::Mat2QImage(image_m);//这一步会把image_m从BGR转为RGB
	showProImage();
}
//获取图片长宽
void imageprocess::getImageInformation()
{
	height_=image_M.rows;
	width_=image_M.cols;
}