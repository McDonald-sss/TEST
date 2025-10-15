#include<opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;



void main()
{

	VideoCapture cap(0);      //��������ͷ
	
	int width = cap.get(CAP_PROP_FRAME_WIDTH);     //��ȡ��ͷͼ��Ŀ�
	int height = cap.get(CAP_PROP_FRAME_HEIGHT);   //��ȡ��ͷͼ��ĸ�
	double fps = cap.get(CAP_PROP_FPS);            //��ȡ��ͷͼ��ķֱ���
	cout << "ͼ���С��" << width << " x " << height << endl;  
	cout << "FPS��" << fps << endl;
		//���ͼ���С�ͷֱ���

	int bright =50; // ��ʼ������
	int baoguang = 0;    // ��ʼ���ع�

	namedWindow("Trackbar", WINDOW_NORMAL); // �������ڴ���
	createTrackbar("Bright", "Trackbar", &bright, 255);
	createTrackbar("baoguang", "Trackbar", &baoguang, 255);

	cap.set(CAP_PROP_BRIGHTNESS, bright);
	cap.set(CAP_PROP_EXPOSURE, baoguang);

	//...�ҵ�����ͷզ��ô��û�á������������ˣ�����˼������ֻ��ֱ���ڴ��������ֵT T

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
