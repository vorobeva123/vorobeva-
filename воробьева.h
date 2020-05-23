#pragma once
#include <cstdlib>
#include <ctime>


template <class T>
class Matrix {
protected:

public:
    T** arr;
    int height;
    int width;

    
    
    Matrix(int height, int width)
    {
       std::cout << "конструктор: " << this << std::endl;
       std::cout << "\n";
        this->height = height;
        this->width = width;
        arr = new T* [this->height];
        for (int i = 0; i < this->height; i++)
            arr[i] = new T[width];

        for (int i = 0; i < this->height; i++)
        {
            for (int j = 0; j < this->width; j++)
            {
                arr[i][j] = 0.1*(rand() % 201-100);
            };
          
        };
        std::cout << std::endl;
    }
		Matrix& operator+(const Matrix& a)
		{
			if (a.line != this->line || a.collumn != this->collumn)
			{
				throw exception("сложение");
			}
			for (int i = 0; i < a.line; i++)
				for (int j = 0; j < a.collumn; j++)
					this->arr[i][j] = a.arr[i][j] + this->arr[i][j];
			return *this;
		}

        Matrix& operator=(const Matrix &SecondMatrix)
            {
            std::cout << "опреатор присваивания матриц: " << this << std::endl;
                this->height = SecondMatrix.height;
                this->width = SecondMatrix.width;
               
                for (int i = 0; i < this->height; i++)
                    delete[] this->arr[i];
                delete[] this->arr;
              
               this-> arr = new float* [this->height];
                for (int i = 0; i < this->height; i++)
                    this->arr[i] = new float[SecondMatrix.width];

                for (int i = 0; i < this->height; i++)
                {
                    for (int j = 0; j < this->width; j++)
                    {
                        this->arr[i][j] = SecondMatrix.arr[i][j];
                    };
                };
                return *this;
            }
		Matrix operator*(const Matrix& a)
		{
			if (this->collumn != a.line)
			{
				throw exception("умножение");
			}
			Matrix c(this->line, a.collumn);
			for (int i = 0; i < c.line; i++)
				for (int j = 0; j < c.collumn; j++)
					c.arr[i][j] = 0;
			for (int i = 0; i < this->line; i++)
				for (int j = 0; j < a.collumn; j++)
					for (int k = 0; k < this->collumn; k++)
						c.arr[i][j] += this->arr[i][k] * a.arr[k][j];
			return c;

		}
        
        void printMatrix()
        {
            std::cout << "функция printMatrix: " << this << std::endl;
            for (int i = 0; i < this->height; i++)
            {
                for (int j = 0; j < this->width; j++)
                    std::cout<<"        "<< arr[i][j] <<"    ";
                std::cout << std::endl;
            }

        }
};



template<class T>
class GaussSolve : public Matrix<T>
{
    
public:
    
  
    GaussSolve(int height, int width) : Matrix<T>(height, width) 
    {

       
    };
    void funcGaussSolve(Matrix<T> matrixToSolve)
    {
        float tmpdef = 0;
        float tmpstring = 0;
        GaussSolve Result(matrixToSolve.height, matrixToSolve.width);
        for (int i = 0; i < matrixToSolve.height; i++)
            for (int j = 0; j < matrixToSolve.width; j++)
            {
                Result.arr[i][j] = matrixToSolve.arr[i][j];
            };
        int tmpsize = 0;
        if (matrixToSolve.height <= matrixToSolve.width)
            tmpsize = matrixToSolve.height;
        else tmpsize = matrixToSolve.width;


        for (int i = 0, j = 0; j < tmpsize; j++, i++)
        {
            if (Result.arr[i][j] != 0)
            {
                tmpdef = Result.arr[i][j];

                std::cout << "tmp koeff: " << tmpdef << " i = " << i << " j= " << j << std::endl;

                for (int k = i + 1, n = matrixToSolve.height - j - 1; n > 0; k++, n--)
                {
                    tmpstring = (-1) * Result.arr[k][j] / tmpdef;
                    std::cout << "tmpstring koeff: " << tmpstring << " k = " << k << std::endl;
                    for (int l = 0; l < matrixToSolve.width; l++)
                    {
                        Result.arr[k][l] = Result.arr[k][l] + Result.arr[i][l] * tmpstring;
                        std::cout << Result.arr[k][l] << "         ";
                    };
                    std::cout << std::endl;
                };
                Result.printMatrix();
            }
            else
            {   
                cout << "koeff = 0"<<endl;
                for (int i = 0; i < matrixToSolve.height-1; i++)
                {
                    if (Result.arr[i][j] == 0)
                    {
                        int tmpswapJ;
                        for (int j = 0; j < matrixToSolve.width; j++)
                        {
                            tmpswapJ = Result.arr[i][j];
                            Result.arr[i][j] = Result.arr[i + 1][j];
                            Result.arr[i + 1][j] = tmpswapJ;
                        };
                    };
                    Result.printMatrix();
                }
                i--;
                j--;
            }
        };
        Result.printMatrix();
        for (int i = matrixToSolve.height - 1; i >= 0;)
        {
            if (Result.arr[i][matrixToSolve.width - 1] == 0)
                i--;
            if ((Result.arr[i][matrixToSolve.width - 1] != 0)
                && (Result.arr[i][matrixToSolve.width - 2] == 0))
            {
                cout << "\n!Решений нет" << endl;
                break;
            };
            if ((Result.arr[i][matrixToSolve.width - 1] != 0)
                && (Result.arr[i][matrixToSolve.width - 2] != 0))
                break;
        };
    
        }




















    };  
};

    

