#include<opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;

Mat img,imgPoint,imgCrop;
Point Point1,Point2;
bool drawing = false;  //�������߰���Ĳ��ۣ���������϶���ʱ�����ڲ�����һ�������ͼ������......

void mouse(int event, int x, int y, int flags, void*)//����¼�����
{
	if (event == EVENT_LBUTTONDOWN)//���������¼��ѡ����
	{
		bool drawing = true;
		Point1 = Point(x, y);

	}

	if (event == EVENT_MOUSEMOVE && (flags & EVENT_FLAG_LBUTTON)) //�϶����,��ʾ��������Լ���굱ǰ���ص����Ϣ
	{
		
		Point2 = Point(x, y);
		img.copyTo(imgPoint);
		rectangle(imgPoint, Point1, Point2, Scalar(255, 0, 255), 5);
		imshow("img Cat", imgPoint);

		Vec3b color = img.at<Vec3b>(y, x);
		int B = color [0];
		int G = color[1];
		int R = color[2];

		cout << "RGB:" << R << "," << G << "," << B << endl;
		cout << "��ǰ���ص�����:" << Point2 << endl;

	}
	if (event == EVENT_LBUTTONUP)  //�ɿ�����γɿ�!
	{
		bool drawing = false;
		
		Point2 = Point(x, y);

		rectangle(img, Point1, Point2, Scalar(255, 0, 255), 5);
		imshow("img Cat", img);

		int X = (Point1.x + Point2.x) / 2;
		int Y = (Point1.y + Point2.y) / 2;

		cout << "���ĵ�����Ϊ��" << "(" << X << "," << Y << ")"<<endl;



		Rect roi(Point1, Point2);
		imgCrop = img(roi);
		imshow("img Crop", imgCrop);

		imwrite("cat2.png", imgCrop);

	}


}

void main()
{



	string path = "cat.png";
	img = imread(path);
	img.copyTo(imgPoint);

	namedWindow("img Cat", WINDOW_GUI_NORMAL);
	resizeWindow("img Cat", 640, 360);
	setMouseCallback("img Cat", mouse);



	imshow("img Cat", img);

	waitKey(0);
}