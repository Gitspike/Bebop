#include<iostream>
#include<cmath>

using namespace std;

class point
{
	public:
		point();
		float x;
		float y; 
		friend float Distance(point a,point b){
			float distance;
			distance=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
			return distance;
		}
};
point::point():x(0),y(0){}

class circle
{
	public:
		point center;
		int radius;
		
}; 
int main()
{
	circle c1,c2;
	cout<< "请输入第一个圆的圆心坐标和半径" <<endl;
	cin >> c1.center.x >> c1.center.y >> c1.radius;
	cout << "请输入第二个圆的圆心坐标和半径" <<endl;
	cin >> c2.center.x >> c2.center.y >> c2.radius;
	float distance=Distance(c1.center,c2.center );
	if (distance > c1.radius+ c2.radius)
		cout << "两圆外离" << endl;
	else if (distance == c1.radius + c2.radius)
		cout << "两圆外切" << endl;
	else if (distance == abs(c1.radius - c2.radius))
		cout << "两圆内切" << endl;
	else if (distance < abs(c1.radius - c2.radius))
		cout << "两圆内含" << endl;
	else cout << "两圆相交" << endl;
	return 0;
}