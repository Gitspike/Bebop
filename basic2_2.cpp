#include<iostream>
#include<cstdlib>
using namespace std;

 class Matrix
{
public:
	int** matrix = NULL;
	int row, col;
	Matrix(int row, int col);
	~Matrix();
	Matrix(Matrix& matrix);
	void inputMatrix();
	void outputMatrix();
	void addMatrix(Matrix A1, Matrix A2);
	void subMatrix(Matrix A1, Matrix A2);
	Matrix& operator=(Matrix& m)
	{
		if (matrix != NULL)
		{
			delete matrix;
			matrix = NULL;
		}
		matrix = new int* [row];
		for (int i = 0; i < row; i++)
		{
			matrix[i] = new int[col];
		}
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				this->matrix[i][j] = m.matrix[i][j];
		return *this;
	}
};
Matrix::Matrix(int row,int col)
{
	this->row = row;
	this->col = col;
	this->matrix = new int* [row];
	for (int i = 0; i < row; i++)
	{
		this->matrix[i] = new int[col];
	}
}


Matrix::~Matrix()
{
	if (matrix != NULL)
	{
		for (int i = 0; i < this->row; i++)
		{
			delete[]matrix[i];
		}
		delete[]matrix;
		this->matrix = NULL;
	}
}


Matrix::Matrix(Matrix& m)
{
	this->row = m.row;
	this->col = m.col;
	this->matrix = new int* [row];
	for (int i = 0; i < row; i++)
	{
		this->matrix[i] = new int[col];
	}
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			this->matrix[i][j] = m.matrix[i][j];
		}
}

void Matrix::inputMatrix()
{
	for(int i=0;i<row;i++)
		for (int j = 0; j < col; j++)
		{
			cin >> this->matrix[i][j];
		}
}

void Matrix::outputMatrix()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << this->matrix[i][j]<<" ";
		}
		cout << endl;
	}

}

void Matrix::addMatrix(Matrix A1, Matrix A2)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			this->matrix[i][j] = A1.matrix[i][j] + A2.matrix[i][j];
}

void Matrix::subMatrix(Matrix A1, Matrix A2)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			this->matrix[i][j] = A1.matrix[i][j] - A2.matrix[i][j];
}

int main()
{
	int row, col;
	cout << "请输入行数：";
	cin >> row;
	cout << "请输入列数：";
	cin >> col;
	Matrix A1(row, col);
	Matrix A2(row, col);
	Matrix A3(row, col);
	cout << "请输入矩阵A1：" << endl;
	A1.inputMatrix();
	cout << "请输入矩阵A2：" << endl;
	A2.inputMatrix();
	
	A3.addMatrix(A1, A2);
	cout << "矩阵A3=A1+A2：" << endl;
	A3.outputMatrix();
	A3.subMatrix(A1, A2);
	cout << "矩阵A3=A1-A2：" << endl;
	A3.outputMatrix();

	//使用拷贝构造函数初始化
	Matrix* pA1 = new Matrix(A1);
	Matrix* pA2 = new Matrix(A2);
	Matrix* pA3 = new Matrix(A3);

	pA3->addMatrix(*pA1, *pA2);//解引用得到对象
	cout << "矩阵pA3=pA1+pA2：" << endl;
	pA3->outputMatrix();
	pA3->subMatrix(*pA1, *pA2);
	cout << "矩阵pA3=pA1-pA2：" << endl;
	pA3->outputMatrix();

	delete pA1;
	delete pA2;
	delete pA3;

	return 0;
}
