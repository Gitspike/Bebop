#include<iostream>

using namespace std;

class Shape
{
	public:
		double area;
		void area_rec(int x,int y);
		void area_c(int r);
		Shape() { cout << "这是Shape类的构造函数" << endl; }
		~Shape() { cout << "这是Shape类的析构函数" << endl; }
};

class rectangle:public Shape
{
public:
	int length;
	int width;
	rectangle() { cout << "这是rectangle类的构造函数" << endl; }
	~rectangle() { cout << "这是rectangle类的析构函数" << endl; }
};

class circle:public Shape
{
	public:
		int r;
		circle() { cout << "这是circle类的构造函数" << endl; }
		~circle() { cout << "这是circle类的析构函数" << endl; }
};

class square: public rectangle
{
	public:
		int side;
		square() { cout << "这是square类的构造函数" << endl; }
		~square() { cout << "这是square类的析构函数" << endl; }
};

void Shape::area_rec(int x,int y)
{
	this->area=x*y;
}

void Shape::area_c(int r)
{
	this->area=3.14*r*r;
}

int main()
{
	square s;
	circle c;
	cout << "请输入正方形的边长" <<endl;
	cin >> s.side;
	s.area_rec(s.side,s.side);
	cout<< "正方形面积为："<< s.area <<endl;
	cout << "请输入圆形的半径" << endl;
	cin >> c.r;
	c.area_c(c.r);
	cout << "圆形的面积为：" << c.area << endl;
	return 0;


}