// 21.04.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "class.h"
using namespace std;
void foo(int x) {
	if (x < 0)
	{
		throw exception("Число меньше 0");
	}
	cout « "Наше число:"« x«endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Vec a = Vec(10), b = Vec(10), c = Vec(10), q = Vec(1);

	for (int i = 0; i < 10; i++)
	{
		a.arr[i] = i;
		b.arr[i] = i;
	}
	q.arr[0] = 5;
	cout « q.arr[0]«endl;
	//cout « a;
	//cout « b;
	/*a.print();
	b.print();*/
	/*c = a + b;*/
	/*c.print();*/
	/* cout « c;*/ //оператор переопределён


	try
	{
		foo(q.arr[0]);
	}
	catch (const std::exception & ex)
	{
		cout « "Мы поймали " « ex.what() « endl;
	}

	//double** arr;
	//int line = 5;
	//int collumn = 5;
	//arr = new double* [line];
	//for (int i = 0; i < line; i++)
	//{
	// arr[i] = new double[collumn];
	// for (int j = 0; j < collumn; j++) {
	// arr[i][j] = 5; // добавить преобразователь в класс
	// }
	//}
	//cout « arr;
	//return 0;
	//Matrix a = Matrix(5, 5);
	//cout « a;
}

но без моего си мэйка не будет работать нарн

#pragma once
#include <iostream>
using namespace std;

class Vec
{
public:
	double* arr;
	int size;
	Vec(int len)
	{
		size = len;
		arr = new double[len];
	}

	friend Vec operator + (Vec const& a, Vec const& b)
	{
		Vec result = Vec(a.size);
		for (int i = 0; i < a.size; i++)
		{
			result.arr[i] = a.arr[i] + b.arr[i];
		}
		return result;
	}


	void print()
	{
		for (int i = 0; i < size; i++)
		{
			std::cout « arr[i] « " ";
		}
		std::cout « "\n";
	}

	friend std::ostream& operator « (std::ostream& out, const Vec& c);


};
std::ostream& operator « (std::ostream& out, const Vec& c)
{
	for (int i = 0; i < 10; i++)
	{
		out « c.arr[i] « " ";
	}
	out « "\n";

	return out;




}

class Matrix
{
public:
	double** arr;
	int line, collumn;
	Matrix(int i, int j)
	{
		line = i;
		collumn = j;
		arr = new double* [line];
		for (int k = 0; k < i; k++)
			arr[k] = new double[collumn]; //добавить зануление всех элементов


	}

	Matrix& operator=(const Matrix& a)
	{
		if (this->collumn > 0)
		{
			for (int i = 0; i < a.line; i++)
				delete[] this->arr[i];

		}
		if (this->line > 0)
		{
			delete[] this->arr;
		}
		this->line = a.line;
		this->collumn = a.collumn;
		this->arr = new double* [a.line];
		for (int i = 0; i < a.line; i++)
			this->arr[i] = new double[a.collumn];
		for (int i = 0; i < a.line; i++)
		{
			for (int j = 0; j < a.collumn; j++)
				this->arr[i][j] = a.arr[i][j];
		}
		return *this;
	}

	friend std::ostream& operator « (std::ostream& out, Matrix& a)
	{
		for (int i = 0; i < a.line; i++)
		{
			for (int j = 0; j < a.collumn; j++)
				out « a.arr[i][j] « " ";
			out « "\n";
		}
		return out;
	}

};

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
