#include<opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;

Mat img,imgHSV,mask,mask1,mask2, imgDil;


int hmin = 0, smin = 0, vmin = 152;
int hmax = 179, smax = 70, vmax = 255;


void main()
{
	string path = "apple.png";
	img = imread(path);
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	/*namedWindow("Trackbars", WINDOW_GUI_NORMAL);
	resizeWindow("Trackbars", 640, 360);

    createTrackbar("Hue Min", "Trackbars", &hmin, 179);
   createTrackbar("Hue Max", "Trackbars", &hmax, 179);
   createTrackbar("Sat Min", "Trackbars", &smin, 255);
   createTrackbar("Sat Max", "Trackbars", &smax, 255);
   createTrackbar("Val Min", "Trackbars", &vmin, 255);
   createTrackbar("Val Max", "Trackbars", &vmax, 255);*/



   //依旧在找苹果的颜色，完成使命后删掉！！！


	

  
   
	   Scalar lower(hmin, smin, vmin);
	   Scalar upper(hmax, smax, vmax);
	   inRange(imgHSV, Scalar(0, 174, 98), Scalar (23, 255, 255) , mask1);
	   inRange(imgHSV, Scalar(0, 97, 234), Scalar (179, 255, 255), mask2);
	   bitwise_or(mask1, mask2, mask);

	   Mat kernel = getStructuringElement(MORPH_RECT, Size(7, 7));
	   dilate(mask, imgDil, kernel);
	  // getContours(imgDil, img);
	   vector<vector<Point>> contours;
	   vector<Vec4i> hierarchy;


	   findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);


	   for (int i = 0; i < contours.size(); i++)
	   {
		   int area = contourArea(contours[i]);
		   cout << area << endl;


		   //获取面积，然后把最大的搞出来
		   vector<Rect>boundRect(contours.size());

		   if (area > 2000)
		   {
			   findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
			   Rect rect = boundingRect(contours[i]);
			   rectangle(img, rect, Scalar(255, 0, 255), 2);

		   }
	   }

	   imshow("img Apple", img);
	   //imshow("img HSV", imgHSV);
	   imshow("img MASK", mask);
	   //imshow("img DIL", imgDil);


	   waitKey(0);
   
}
