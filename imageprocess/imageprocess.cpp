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
//���Ȼ�������ʼ��
void imageprocess::sliderForBrightInit()
{
	sliderForBright->setMaximumSize(QSize(100,50));
	sliderForBright->setOrientation(Qt::Horizontal);

	sliderForBright->setMinimum(-255);
	sliderForBright->setMaximum(255);
	sliderForBright->setValue(0);//һ��Ҫ��������Сֵ�����ֵ֮�������õ�ǰֵ

	sliderForBright->setToolTip(QString::fromLocal8Bit("����"));
	ui.mainToolBar->addWidget(sliderForBright);
	ui.mainToolBar->addSeparator();
}
//�ԱȶȻ�������ʼ��
void imageprocess::sliderForContrastInit()
{
	sliderForContrast->setMaximumSize(QSize(100,50));
	sliderForContrast->setOrientation(Qt::Horizontal);
	
	sliderForContrast->setMinimum(0);
	sliderForContrast->setMaximum(200);
	sliderForContrast->setValue(100);//һ��Ҫ��������Сֵ�����ֵ֮�������õ�ǰֵ

	sliderForContrast->setToolTip(QString::fromLocal8Bit("�Աȶ�"));
	ui.mainToolBar->addWidget(sliderForContrast);
	ui.mainToolBar->addSeparator();
}
//��ֵ��������ʼ��
void imageprocess::sliderForThresholdInit()
{
	sliderForThreshold->setMaximumSize(QSize(100,50));
	sliderForThreshold->setOrientation(Qt::Horizontal);

	sliderForThreshold->setMinimum(-1);
	sliderForThreshold->setMaximum(255);
    sliderForThreshold->setValue(122);//һ��Ҫ��������Сֵ�����ֵ֮�������õ�ǰֵ

	sliderForThreshold->setToolTip(QString::fromLocal8Bit("��ֵ"));
	ui.mainToolBar->addWidget(sliderForThreshold);
	ui.mainToolBar->addSeparator();
}
//�ı����ȶ�
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
	image_Q=M2Q::Mat2QImage(image_M);//��һ�����image_M��BGRתΪRGB
	showProImage();
	//cvtColor(image_M,image_M,COLOR_RGB2BGR);//����תΪBGR
	flags_brightness++;
	image_M_T=image_M.clone();//Ŀ�����ڵ�����ֵ��ʱ��ʹimage_M������µ�ֵ
}
//�ı�Աȶ�
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
	image_Q=M2Q::Mat2QImage(image_M);//��һ�����image_M��BGRתΪRGB
	showProImage();
	//cvtColor(image_M,image_M,COLOR_RGB2BGR);//����תΪBGR
	flags_contrast++;
	image_M_T=image_M.clone();//Ŀ�����ڵ�����ֵ��ʱ��ʹimage_M������µ�ֵ
}

//�ı���ֵ
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
	cvtColor(image_M,image_M,COLOR_GRAY2BGR);//����תΪBGR
	flags_threhold++;
	image_M_=image_M.clone();//Ŀ�����ڵ������ȺͶԱȶȵ�ʱ��ʹimage_M������µ�ֵ

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
	//cvtColor(image_M,image_M,COLOR_GRAY2BGR);//����תΪBGR
	//flags_threhold++;
}

//��ͼƬ����ʾ
void imageprocess::getAndShowImage()
{
	QString fileName = QFileDialog::getOpenFileName(this,"Open Image",".","Image File(*.png *.jpg *.jpeg *.bmp)");
	if(fileName.isEmpty())
		return;
	image_M=imread(fileName.toLocal8Bit().data());

	getImageInformation();
	char str[100];
	sprintf(str,"��ȣ�%d",width_);
	lableHight->setText(QString::fromLocal8Bit(str));
	sprintf(str,"�߶ȣ�%d",height_);
	lableWidth->setText(QString::fromLocal8Bit(str));
	QString str1=QString::fromLocal8Bit("λ�ã�");
	lableRoot->setText(str1.append(fileName));

	image_M_I=image_M.clone();
	image_M_=image_M.clone();//Ŀ�����ڵ������ȺͶԱȶȵ�ʱ��ʹimage_M������µ�ֵ
	image_M_T=image_M.clone();//Ŀ�����ڵ�����ֵ��ʱ��ʹimage_M������µ�ֵ
	image_Q=M2Q::Mat2QImage(image_M);//��һ�����image_M��BGRתΪRGB
	showGetImage();
	showProImage();
	//cvtColor(image_M,image_M,COLOR_RGB2BGR);//����תΪBGR

	ui.mainToolBar->setEnabled(true);
	ui.menu_edge->setEnabled(true);
	ui.menu_histogram->setEnabled(true);
	ui.menu_line->setEnabled(true);
	ui.menu_nonline->setEnabled(true);
	ui.actionFacedetect->setEnabled(true);
	ui.actionErode->setEnabled(true);
	ui.actionDilate->setEnabled(true);

}
//��ʾ��ȡ����ͼƬ
void imageprocess::showGetImage()
{
	//ui.label->setScaledContents(true);
	
	ui.label->setGeometry(80,30,image_Q.width()/10,image_Q.height()/10);
	ui.label->setPixmap(QPixmap::fromImage(image_Q.scaled(image_Q.width()/10,image_Q.height()/10))); 
	//ui.label->setPixmap(QPixmap::fromImage(image_Q.scaled(10,20))); 
	qDebug()<<image_Q.height();
	qDebug()<<image_Q.width();
	//ui.label->setPixmap(QPixmap::fromImage(image_Q.scaled(ui.label->size()))); 
	//û��//ui.label->setScaledContents(true);
	//û��//ui.label->setPixmap(QPixmap::fromImage(image_Q)); 
	//û��//ui.label->resize(ui.label->pixmap()->size()); 
	
	lableShow->clear();
	lableGet->setPixmap(QPixmap::fromImage(image_Q)); 
	lableGet->resize(QSize(image_Q.width(),image_Q.height()));
		
}
//��ʾ������ͼƬ
void imageprocess::showProImage()
{
	lableShow->setPixmap(QPixmap::fromImage(image_Q));  
	lableShow->resize(QSize(image_Q.width(),image_Q.height()));
}
//Canny��Ե���
void imageprocess::canny_()
{
	if(image_M.channels()==3)
		cvtColor(image_M,image_M,COLOR_BGR2GRAY);
	Canny(image_M, image_M, 40, 90);//30��ʾ����ֵ��80��ʾ����ֵ���Ƽ��ߵ���ֵ��ֵ��2:1��3:1֮��
	image_Q=M2Q::Mat2QImage(image_M);
	showProImage();
	cvtColor(image_M,image_M,COLOR_GRAY2BGR);//����תΪBGR
	image_M_=image_M.clone();//Ŀ�����ڵ������ȺͶԱȶȵ�ʱ��ʹimage_M������µ�ֵ
	image_M_T=image_M.clone();//Ŀ�����ڵ�����ֵ��ʱ��ʹimage_M������µ�ֵ
}
//Sobel��Ե���
void imageprocess::sobel_()
{
	if(image_M.channels()==3)
		cvtColor(image_M,image_M,COLOR_BGR2GRAY);
	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y, dst;
	Sobel(image_M, grad_x, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);//����x����
	convertScaleAbs(grad_x, abs_grad_x);

	Sobel(image_M, grad_y, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);//����y����
	convertScaleAbs(grad_y, abs_grad_y);

	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, image_M);

	image_Q=M2Q::Mat2QImage(image_M);
	showProImage();
	cvtColor(image_M,image_M,COLOR_GRAY2BGR);//����תΪBGR
	image_M_=image_M.clone();//Ŀ�����ڵ������ȺͶԱȶȵ�ʱ��ʹimage_M������µ�ֵ
	image_M_T=image_M.clone();//Ŀ�����ڵ�����ֵ��ʱ��ʹimage_M������µ�ֵ
}
//Laplacian��Ե���
void imageprocess::laplacian_()
{
	if(image_M.channels()==3)
		cvtColor(image_M,image_M,COLOR_BGR2GRAY);
	Mat dst;
	Laplacian(image_M, dst, CV_16S, 3, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(dst, image_M);

	image_Q=M2Q::Mat2QImage(image_M);
	showProImage();
	cvtColor(image_M,image_M,COLOR_GRAY2BGR);//����תΪBGR
	image_M_=image_M.clone();//Ŀ�����ڵ������ȺͶԱȶȵ�ʱ��ʹimage_M������µ�ֵ
	image_M_T=image_M.clone();//Ŀ�����ڵ�����ֵ��ʱ��ʹimage_M������µ�ֵ
}
//��ʴ
void imageprocess::erode_()
{
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(5, 5),Point(-1,-1));
	//���ָ���ĺˣ������˵���״�ʹ�С��MORPH_ELLIPSEָ������Բ�������Point(-1,-1)�Ǻ˵��ڲ�������λ��
	erode(image_M, image_M, element, Point(-1, -1), 1);//��ʴ���������һ��1�Ǹ�ʴ�Ĵ��������Point(-1��-1)����ûʲô��
	image_Q=M2Q::Mat2QImage(image_M);//��һ�����image_M��BGRתΪRGB
	showProImage();
	//cvtColor(image_M,image_M,COLOR_RGB2BGR);//����תΪBGR
	image_M_=image_M.clone();//Ŀ�����ڵ������ȺͶԱȶȵ�ʱ��ʹimage_M������µ�ֵ
	image_M_T=image_M.clone();//Ŀ�����ڵ�����ֵ��ʱ��ʹimage_M������µ�ֵ
}
//����
void imageprocess::dilate_()
{
	Mat element = getStructuringElement(MORPH_ELLIPSE, Size(5, 5),Point(-1,-1));
	//���ָ���ĺˣ������˵���״�ʹ�С��MORPH_ELLIPSEָ������Բ�������Point(-1,-1)�Ǻ˵��ڲ�������λ��
	dilate(image_M,image_M, element, Point(-1, -1), 1);//���Ͳ��������һ��1�����͵Ĵ���
	image_Q=M2Q::Mat2QImage(image_M);//��һ�����image_M��BGRתΪRGB
	showProImage();
	//cvtColor(image_M,image_M,COLOR_RGB2BGR);//����תΪBGR
	image_M_=image_M.clone();//Ŀ�����ڵ������ȺͶԱȶȵ�ʱ��ʹimage_M������µ�ֵ
	image_M_T=image_M.clone();//Ŀ�����ڵ�����ֵ��ʱ��ʹimage_M������µ�ֵ
}
//ͨ��ֱ��ͼ
void imageprocess::commenChannel(const int &channel,const int &channel_b,const int &channel_g,const int &channel_r,const Mat&img,const char *winTitle)
{
	int nimg = 1;  //img�д��ͼ��ĸ���
	int dims = 1;  //��Ҫͳ�Ƶ�������Ŀ(ֻͳ�ƻҶ�ֵ)
	int channels =channel; //ͨ��������
	MatND dstHist;  //����洢ֱ��ͼ������ı��������������Ϊ22��������Ϊ333�ĵ��ʾ�Ҷ�Ϊ22�ĵ���333��
	int bins = 256; //ֱ��ͼ�ĺ�����̶ȸ��� 0��255һ��256���̶�
	float hranges[] = {0, 256};  //��Χ[0,256)ע�������ֵ��1
	int maxHeight=200;//���߶�
	const float* ranges[] = {hranges};

	calcHist(&img, nimg, &channels, Mat(), dstHist, dims, &bins, ranges);//����ֱ��ͼ

	Mat dstImg(bins, bins*3, CV_8UC3, Scalar(240,240,240));  //������ʾֱ��ͼ�����ͼ��
	double maxValue ;//����ֱ��ͼ���������ֵ
	minMaxLoc(dstHist, 0, &maxValue, 0, 0);
	int scale = 3;//���
	for(int i=0; i<256; i++)
	{
		float binValue = dstHist.at<float>(i);
		int realValue;
		if(maxValue==0)
			realValue=0;
		else
			realValue= saturate_cast<int>(binValue*maxHeight/maxValue);  //��һ�����ݣ�������ȡ��
		line(dstImg, Point(i*scale, bins), Point(i*scale, bins-realValue), Scalar(channel_b, channel_g, channel_r), 1, 8);
	}
	imshow(winTitle,dstImg);
}
//rͨ��ֱ��ͼ
void imageprocess::r_(const int &channel,const int &channel_b,const int &channel_g,const int &channel_r)
{
	if(image_M.channels()==1)
		QMessageBox::warning
		(
		this, 
		QString::fromLocal8Bit("����"),
		QString::fromLocal8Bit("��ǰ�����ͼƬ�ǵ�ͨ������ʹ�ûҶ�ֱ��ͼ")
		);  
	else
		commenChannel(channel,channel_b,channel_g,channel_r,image_M,"Rͨ��ֱ��ͼ");
}
//gͨ��ֱ��ͼ
void imageprocess::g_(const int &channel,const int &channel_b,const int &channel_g,const int &channel_r)
{	
	if(image_M.channels()==1)
		QMessageBox::warning
		(
		this, 
		QString::fromLocal8Bit("����"),
		QString::fromLocal8Bit("��ǰ�����ͼƬ�ǵ�ͨ������ʹ�ûҶ�ֱ��ͼ")
		);  
	else
	commenChannel(channel,channel_b,channel_g,channel_r,image_M,"Gͨ��ֱ��ͼ");
}
//bͨ��ֱ��ͼ
void imageprocess::b_(const int &channel,const int &channel_b,const int &channel_g,const int &channel_r)
{
	if(image_M.channels()==1)
		QMessageBox::warning
		(
		this, 
		QString::fromLocal8Bit("����"),
		QString::fromLocal8Bit("��ǰ�����ͼƬ�ǵ�ͨ������ʹ�ûҶ�ֱ��ͼ")
		);  
	else
	commenChannel(channel,channel_b,channel_g,channel_r,image_M,"Bͨ��ֱ��ͼ");
}
//�Ҷ�ֱ��ͼ
void imageprocess::gray_(const int &channel,const int &channel_b,const int &channel_g,const int &channel_r)
{
	
	Mat image_m=image_M.clone();
	if(image_m.channels()!=1)
	cvtColor(image_m,image_m,CV_BGR2GRAY);
	commenChannel(channel,channel_b,channel_g,channel_r,image_m,"�Ҷ�ֱ��ͼ");
}
//���ò���
void imageprocess::reset()
{
	image_M=image_M_I.clone();
	image_Q=M2Q::Mat2QImage(image_M);//��һ�����image_M��BGRתΪRGB
	showProImage();
	//cvtColor(image_M,image_M,COLOR_RGB2BGR);//����תΪBGR

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
//�����˲�
void imageprocess::boxFilter_()
{
	boxFilter(image_M, image_M, -1, Size(3, 3), Point(-1, -1), false);  //�����˲���
	image_Q=M2Q::Mat2QImage(image_M);//��һ�����image_M��BGRתΪRGB
	showProImage();
	//cvtColor(image_M,image_M,COLOR_RGB2BGR);//����תΪBGR
	image_M_=image_M.clone();//Ŀ�����ڵ������ȺͶԱȶȵ�ʱ��ʹimage_M������µ�ֵ
	image_M_T=image_M.clone();//Ŀ�����ڵ�����ֵ��ʱ��ʹimage_M������µ�ֵ
}
//��ֵ�˲�
void imageprocess::blur_()
{
	blur(image_M, image_M, Size(3,3));  //��ֵ�˲�
	image_Q=M2Q::Mat2QImage(image_M);//��һ�����image_M��BGRתΪRGB
	showProImage();
	//cvtColor(image_M,image_M,COLOR_RGB2BGR);//����תΪBGR
	image_M_=image_M.clone();//Ŀ�����ڵ������ȺͶԱȶȵ�ʱ��ʹimage_M������µ�ֵ
	image_M_T=image_M.clone();//Ŀ�����ڵ�����ֵ��ʱ��ʹimage_M������µ�ֵ
}
//��˹�˲�
void imageprocess::GaussianBlur_()
{
	GaussianBlur(image_M, image_M, Size(3,3), 0,0);//��˹�˲���û����ϵ����ô����
	image_Q=M2Q::Mat2QImage(image_M);//��һ�����image_M��BGRתΪRGB
	showProImage();
	//cvtColor(image_M,image_M,COLOR_RGB2BGR);//����תΪBGR
	image_M_=image_M.clone();//Ŀ�����ڵ������ȺͶԱȶȵ�ʱ��ʹimage_M������µ�ֵ
	image_M_T=image_M.clone();//Ŀ�����ڵ�����ֵ��ʱ��ʹimage_M������µ�ֵ
}
//��ֵ�˲�
void imageprocess::medianBlur_()
{
	medianBlur(image_M, image_M, 5);//��ֵ�˲�
	image_Q=M2Q::Mat2QImage(image_M);//��һ�����image_M��BGRתΪRGB
	showProImage();
	//cvtColor(image_M,image_M,COLOR_RGB2BGR);//����תΪBGR
	image_M_=image_M.clone();//Ŀ�����ڵ������ȺͶԱȶȵ�ʱ��ʹimage_M������µ�ֵ
	image_M_T=image_M.clone();//Ŀ�����ڵ�����ֵ��ʱ��ʹimage_M������µ�ֵ
}
//˫���˲�
void imageprocess::bilateralFilter_()
{
	Mat image_m;
	bilateralFilter(image_M, image_m, 5, 20.0, 10.0);//˫���˲�
	image_M=image_m.clone();
	image_Q=M2Q::Mat2QImage(image_M);//��һ�����image_M��BGRתΪRGB
	showProImage();
//	cvtColor(image_M,image_M,COLOR_RGB2BGR);//����תΪBGR
	image_M_=image_M.clone();//Ŀ�����ڵ������ȺͶԱȶȵ�ʱ��ʹimage_M������µ�ֵ
	image_M_T=image_M.clone();//Ŀ�����ڵ�����ֵ��ʱ��ʹimage_M������µ�ֵ
}
//�������
void imageprocess::faceDetect()
{
	string xmlPath="haarcascade_frontalface_default.xml"; 
	CascadeClassifier ccf;   //��������������
	   
	if(!ccf.load(xmlPath))   //����ѵ���ļ�
	{
		cout<<"���ܼ���ָ����xml�ļ�"<<endl;
		return ;
	}
	vector<Rect> faces;  //����һ�������������������
	Mat gray;
	Mat image_m=image_M.clone();
	cvtColor(image_m,gray,COLOR_BGR2GRAY); //ת���ɻҶ�ͼ����Ϊharr�����ӻҶ�ͼ����ȡ
	equalizeHist(gray,gray);  //ֱ��ͼ������
	ccf.detectMultiScale(gray,faces,1.1,3,0,Size(10,10),Size(400,400)); //�������
	for(vector<Rect>::const_iterator iter=faces.begin();iter!=faces.end();iter++)
	{
		rectangle(image_m,*iter,Scalar(108,226,108),2,8); //������������
	}
	image_Q=M2Q::Mat2QImage(image_m);//��һ�����image_m��BGRתΪRGB
	showProImage();
}
//��ȡͼƬ����
void imageprocess::getImageInformation()
{
	height_=image_M.rows;
	width_=image_M.cols;
}