#include <iostream>
using namespace std;
//#include <string>//stringͷ�ļ�����
#include<cmath>//�����õ�
#include<iomanip>//������λС���õ�

struct Point
{
	//Point���캯��
	Point(double x=0,double y=0)//��ʼ��x y,Ĭ���������Ϊ��0��0��
	{
		//����x y
		X = x;
		Y = y;

	}

	double X;
	double Y;

};
struct Rect
{
	//Rect���캯��
	Rect(int input_id,int input_color,Point input_point,double input_width,double input_height)
	{
		//��������
		ID = input_id;
		this->color = input_color;
		this->point = input_point;
		this->width = input_width;
		this->height = input_height;
	}//��ͳ��ʽ��ʼ��

	int ID;
	int color;
	Point point;//���Ͻ�����
	double width;
	double height;
};

class Armor
{
private:
	Rect rect;//��������

public:

	Armor (Rect r):rect(r){}//��ʼ���б�
	
	Point Center_Point()
	{
		double Center_x = rect.point.X + rect.width / 2;  //�������ĵ�x�����꣬�����Ͻ�����Ϊԭ��(0,0)����������Ϊx��y����������������ĵ��x����Ϊԭ���������һ��Ŀ��
		double Center_y = rect.point.Y + rect.height / 2;  //ͬ��
		return Point(Center_x, Center_y);
	}

	double Diagonal()
	{
		double diagonal = sqrt(rect.width * rect.width + rect.height * rect.height);//���ɶ������Խ��ߵ�ƽ�� ������
		return diagonal;

	}

	void Armor_Point()
	{
		double x = rect.point.X;
		double y = rect.point.Y;
		double h = rect.height;
		double w = rect.width;

		Point p1(x, y);//���Ͻ�
		Point p2(x+w,y);//���Ͻ�
		Point p3(x+w,y+h);//���½�
		Point p4(x,y+h);//���½�
	
		cout << "(" << p1.X << "," << p1.Y << ")" ;
		cout << "(" << p2.X << "," << p2.Y << ")" ;
		cout << "(" << p3.X << "," << p3.Y << ")" ;
		cout << "(" << p4.X << "," << p4.Y << ")" << endl;
	}


	string Armor_Color()
	{
		return (rect.color == 1 )? "��" : "��";
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

	cin >> ID >> color;					//�����һ��
	cin >> x >> y >> width >> height;	//����ڶ���
	Point p1(x, y);						//����point����
	Rect rect(ID,color,p1,width,height);//ͬ�ϣ�����rectʵ��

	Armor armor(rect);//����armor��ʵ��
	Point center = armor.Center_Point();	//���������

	cout << "ID��" << armor.GetID() << "  " << "��ɫ��" << armor.Armor_Color() << endl;//�����һ��
	cout << "(" << center.X << "," << center.Y << ")"<< "  " << "���ȣ�" << fixed << setprecision(2) << armor.Diagonal() << endl;//����ڶ���
	
	//����������һ��ʼ������ô�Ķ�һֱ�������λС��������ȥ������ѧ�ĳ�ʼ��Ĭ�Ͼ���...
	cout.unsetf(ios_base::floatfield);
	cout.precision(6);

	armor.Armor_Point();       //���ú���ֱ�����������

	system("pause");
	return 0;
}