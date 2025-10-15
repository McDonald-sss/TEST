#include<opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;



void main()
{

	VideoCapture cap(0);      //创建摄像头
	
	int width = cap.get(CAP_PROP_FRAME_WIDTH);     //获取镜头图像的宽
	int height = cap.get(CAP_PROP_FRAME_HEIGHT);   //获取镜头图像的高
	double fps = cap.get(CAP_PROP_FPS);            //获取镜头图像的分辨率
	cout << "图像大小：" << width << " x " << height << endl;  
	cout << "FPS：" << fps << endl;
		//输出图像大小和分辨率

	int bright =50; // 初始化亮度
	int baoguang = 0;    // 初始化曝光

	namedWindow("Trackbar", WINDOW_NORMAL); // 创建调节窗口
	createTrackbar("Bright", "Trackbar", &bright, 255);
	createTrackbar("baoguang", "Trackbar", &baoguang, 255);

	cap.set(CAP_PROP_BRIGHTNESS, bright);
	cap.set(CAP_PROP_EXPOSURE, baoguang);

	//...我的摄像头咋怎么打都没用。两个都调不了，何意思。。。只能直接在代码里改数值T T

	Mat img;
	
	VideoWriter writer("VEDIO.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, Size(width, height));

	while (true)
	{
		cap.read(img);

		imshow("Image",img);
		
		writer.write(img);
		
		waitKey(1);
	}

}
