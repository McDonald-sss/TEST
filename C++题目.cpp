#include <iostream>
using namespace std;
//#include <string>//string头文件警告
#include<cmath>//开根用的
#include<iomanip>//保留两位小数用的

struct Point
{
	//Point构造函数
	Point(double x=0,double y=0)//初始化x y,默认情况坐标为（0，0）
	{
		//输入x y
		X = x;
		Y = y;

	}

	double X;
	double Y;

};
struct Rect
{
	//Rect构造函数
	Rect(int input_id,int input_color,Point input_point,double input_width,double input_height)
	{
		//输入数据
		ID = input_id;
		this->color = input_color;
		this->point = input_point;
		this->width = input_width;
		this->height = input_height;
	}//传统方式初始化

	int ID;
	int color;
	Point point;//左上角坐标
	double width;
	double height;
};

class Armor
{
private:
	Rect rect;//创建对象

public:

	Armor (Rect r):rect(r){}//初始化列表
	
	Point Center_Point()
	{
		double Center_x = rect.point.X + rect.width / 2;  //计算中心点x的坐标，记左上角坐标为原点(0,0)，向右向下为x，y轴的正方向。所以中心点的x坐标为原点坐标加上一半的宽度
		double Center_y = rect.point.Y + rect.height / 2;  //同上
		return Point(Center_x, Center_y);
	}

	double Diagonal()
	{
		double diagonal = sqrt(rect.width * rect.width + rect.height * rect.height);//勾股定理计算对角线的平方 并开根
		return diagonal;

	}

	void Armor_Point()
	{
		double x = rect.point.X;
		double y = rect.point.Y;
		double h = rect.height;
		double w = rect.width;

		Point p1(x, y);//左上角
		Point p2(x+w,y);//右上角
		Point p3(x+w,y+h);//右下角
		Point p4(x,y+h);//左下角
	
		cout << "(" << p1.X << "," << p1.Y << ")" ;
		cout << "(" << p2.X << "," << p2.Y << ")" ;
		cout << "(" << p3.X << "," << p3.Y << ")" ;
		cout << "(" << p4.X << "," << p4.Y << ")" << endl;
	}


	string Armor_Color()
	{
		return (rect.color == 1 )? "红" : "蓝";
	}

	int GetID()
	{
		return rect.ID;
	}

};


int main()
{
	int ID, color;
	double x, y, width, height;

	cin >> ID >> color;					//输入第一行
	cin >> x >> y >> width >> height;	//输入第二行
	Point p1(x, y);						//创建point对象
	Rect rect(ID,color,p1,width,height);//同上，创建rect实例

	Armor armor(rect);//创建armor类实例
	Point center = armor.Center_Point();	//创建点对象

	cout << "ID：" << armor.GetID() << "  " << "颜色：" << armor.Armor_Color() << endl;//输出第一行
	cout << "(" << center.X << "," << center.Y << ")"<< "  " << "长度：" << fixed << setprecision(2) << armor.Diagonal() << endl;//输出第二行
	
	//下面这两行一开始不管怎么改都一直在输出两位小数，所以去网上现学的初始化默认精度...
	cout.unsetf(ios_base::floatfield);
	cout.precision(6);

	armor.Armor_Point();       //调用函数直接输出第三行

	system("pause");
	return 0;
}