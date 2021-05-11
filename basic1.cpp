#include<iostream>

using namespace std;


int** init();
void input(int** p);
void output(int** A);
void add(int** A1,int** A2,int** A3);
void sub(int** A1,int** A2,int** A3);
void deletematrix(int** p);
int main()
{
	int** A1;
	int** A2;
	int** A3=init();
	A1=init();
	input(A1);
	A2=init();
	input(A2);
	add(A1,A2,A3);
	cout << "A1+A2的结果是：" <<endl;
	output(A3);
	sub(A1,A2,A3);
	cout << "A1-A2的结果是：" <<endl;
	output(A3);
	deletematrix(A1);
	deletematrix(A2);
	deletematrix(A3);
	return 0; 
 } 
int** init()
{
	int** p=new int*[4];
	for(int i=0;i<4;i++)
		p[i]=new int[5];
	return p;
}
void input(int** p)
{
	cout<< "请输入矩阵元素" <<endl;
	for(int i=0;i<4;i++)
		for(int j=0;j<5;j++)
			cin >> p[i][j]; 
}
void output(int** A)
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<5;j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}
void add(int** A1,int** A2,int** A3)
{
	for(int i=0;i<4;i++)
		for(int j=0;j<5;j++)
			A3[i][j]=A1[i][j]+A2[i][j];
}
void sub(int** A1,int** A2,int** A3)
{
	for(int i=0;i<4;i++)
		for(int j=0;j<5;j++)
			A3[i][j]=A1[i][j]-A2[i][j];
}
void deletematrix(int** p)
{
	for(int i=0;i<4;i++)
		delete []p[i];
	delete []p;
 } 