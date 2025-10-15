#include<opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>
using namespace cv;
using namespace std;

Mat img,imgHSV, mask,imgResize, imgCanny, imgDil;
int hmin = 0, smin = 0, vmin = 152;
int hmax = 179, smax = 70, vmax = 255;

//ͨ��createTrackbar�ҵ���ֵ

void getContours(Mat &imgDil,Mat &cannyColor)
{
    vector<vector<Point>> contours;
    vector<Vec4i>hierarchy;
    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    drawContours(cannyColor, contours, -1, Scalar(255, 255, 0), 2);

}


void main()
{
    string path = "test111.png";
    Mat img = imread(path);

    //cvtColor(img, imgHSV, COLOR_BGR2HSV);

    resize(img, imgResize, Size(1280, 640));


    //�ڸ�ͼ���С


    namedWindow("Image", WINDOW_GUI_NORMAL);
    resizeWindow("Image",640, 360);

    namedWindow("Image Mask", WINDOW_GUI_NORMAL);
    resizeWindow("Image Mask", 640, 360);

    namedWindow("Image cannyColor", WINDOW_GUI_NORMAL);
    resizeWindow("Image cannyColor", 640, 360);

    //���ڸĴ��ڴ�С��ԭ����̫���ˣ�������Ļռ����



    /*createTrackbar("Hue Min", "Trackbars", &hmin, 179);
    createTrackbar("Hue Max", "Trackbars", &hmax, 179);
    createTrackbar("Sat Min", "Trackbars", &smin, 255);
    createTrackbar("Sat Max", "Trackbars", &smax, 255);
    createTrackbar("Val Min", "Trackbars", &vmin, 255);
    createTrackbar("Val Max", "Trackbars", &vmax, 255);*/

    //�������Һ�ɫ���ֵ�hsv�����ֵ����Сֵ�����ʹ���Ѿ���ɣ�ע�͵�!!


        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);

        //����������ɫ��Χ�����Ը����ɫ������

        inRange(imgResize, lower, upper, mask); //��һ��Ĵ��ڣ���^^


        Canny(mask, imgCanny, 25, 75);//Canny��Ե��ȡ
        Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
        dilate(imgCanny, imgDil, kernel);
        Mat cannyColor;
        cvtColor(imgDil, cannyColor, COLOR_GRAY2BGR);

      
       getContours(imgDil,cannyColor);
        imshow("Image", imgResize);
       // imshow("Image HSV", imgHSV);       ����hsv�����ǲ�����...������������������㣬noooo����ע�͵�
        imshow("Image Mask", mask);
        imshow("Image cannyColor", cannyColor);

        imwrite("cannycolor2.png", cannyColor);

        waitKey(0);
    
}