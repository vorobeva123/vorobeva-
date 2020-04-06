// vorobeva1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

class Vector
{
	int x;
	int y;
	int z;
public:
	Vector(int x, int y, int _z) :
		x(_x), y(_y), z(_z)
	{
		cout«"just writing from Vector";
	}
	Vector(const Vector& vector) :
		x(vector.x),
		y(vector.y),
		z(vector.z)
	{
		cout « "copy writing from Vector";
	}
	int getx();
	int gety();
	int getz();
	friend Vector operator+(Vector const& a, Vector const& b)
	{
		int g = a.x + b.x;
		int h = a.y + b.y;
		int j = a.z + b.z;
		Vector c(g, h, j);
		return c;
	}
	friend Vector operator*(Vector const& a, Vector const& b)
	{
		int g = a.x * b.x;
		int h = a.y * b.y;
		int j = a.z * b.z;
		Vector c(g, h, j);
		return c;
	}
};
int Vector::getx() { return x; }
int Vector::gety() { return y; }
int Vector::getz() { return z; }
class Matrix
{
	int* a;
	int column;
	int row;
public:
	Matrix(int column, int row) :
		column(_column), row(_row)
	{
		a = new int[row * column];
		for (int i = 0; i < row; i++)
		{
			a[i] = 1; /*rand() % 10;*/
		}
		cout « "just writing from Matrix\n";
	}
	Matrix(int arr[]) :row(0), column(0) //for квадратных матриц
	{
		int i1 = 0;
		while (arr[i1++] != NULL)
			row++;
		column = row;
		a = new int[row * column];
		for (int i = 0; i < row * column; i++)
		{
			a[i] = arr[i];
		}
		memcpy(a, arr, sizeof(row * column));
	}
	Matrix(const Matrix& matrix) :
		column(matrix.column),
		row(matrix.row)
	{
		a = new int[row * column];
		for (int i = 0; i < row * column; i++)
		{
			a[i] = matrix.a[i];
		}
		memcpy(a, matrix.a, sizeof(row * column));
		cout « "copy writing from Matrix\n";
	}
	void getm();
	friend Matrix operator*(Matrix const& c, Matrix const& b)
	{
		int* ar = new int[c.row * c.column];
		int p1 = 0;
		int p2 = 0;
		for (int i = 0; i < c.column; i++)
		{
			for (int j = 0; j < c.row; j++)
			{
				ar[i] = (c.a[j + p2]) * (b.a[j + p1]);
				p1 += c.row;
			}
			ar[i] = qque;
			p2 += c.column;
			p1 = 0;
		}
		Matrix p12(ar);
		return p12;
	}
	~Matrix()
	{
		delete[] a;
	}
};
void Matrix::getm()
{
	for (int k = 0; k < row; k++)
	{
		for (int i = 0; i < column; i++)
		{
			cout « a[i] « "\t";
		}
		cout « "\n";
	}
}
int main()
{
	Vector q(3, 4, 1);
	cout « " " « q.getx() « " " « q.gety() « " " « q.getz()«endl;
	Vector w(6, 2, 1);
	cout « " " « w.getx() « " " « w.gety() « " " « w.getz()«endl;
	Vector e = q;
	cout « " " « e.getx() « " " « e.gety() « " " « e.getz()«endl;
	Vector m = operator+ (q, w);
	cout « " " « m.getx() « " " « m.gety() « " " « m.getz() « endl;
	Vector n = operator* (q, w);
	cout « " " « n.getx() « " " « n.gety() « " " « n.getz() « endl;
	Matrix r(2, 2);
	r.getm();
	Matrix t = r;
	t.getm();
	Matrix y = operator*(r, t);
	y.getm();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
