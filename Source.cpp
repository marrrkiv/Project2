#include <iostream>
using namespace std;

class Matrix
{
private:

	int** M;
	int n;

public:

	Matrix(int size);
	Matrix(const Matrix &matrix) :
		M(matrix.M), n(matrix.n)
	{}
	void Input();
	void Print();
	void Trace();
	void sumUp();
	void sumDown();
	~Matrix();
};

Matrix::Matrix(int size)
{
	n = size;
	M = new int*[n];
	for (int i = 0;i < n;i++)
		M[i] = new int[n];
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			M[i][j] = 0;
	cout << "\n";
}

Matrix::~Matrix()
{
	for (int i = 0;i < n;i++)
		delete[]M[i];
	delete[]M;
}

void Matrix::Input()
{
	for (int i = 0; i < n ; i++)
		for (int j = 0;j < n;j++)
		{
			cout << "[" << i << "][" << j << "]=";
			cin >> M[i][j];
			cout << "\n";
		}
}

void Matrix::Print()
{
	cout << " YOUR MATRIX : " << "\n";
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
			cout << " " << this->M[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";
}

void Matrix::Trace()
{
	int k = 0;
	for (int i = 0;i < n;i++)
	{
		k += M[i][i];
	}
	cout << " TRACE OF MATRIX = " << k << "\n";
}

void Matrix::sumUp()
{
	int result = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			result += M[i][j];
		}
	cout << " SUM UP = " << result << endl;
}

void Matrix::sumDown()
{
	int result = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			result += M[j][i];
		}
	cout << " SUM DOWN = " << result << endl;
}


int main()
{
	int n;
	cout << "COUNT OF ELEMENTS IN MATRIX : ";
	cin >> n;
	Matrix A(n);
	A.Input();
	A.Print();
	A.Trace();
	A.sumUp();
	A.sumDown();
	return 0;
}