// Zad2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <random>
#include <time.h>
#include <iomanip>

using namespace std;

struct Matrica {

	float** m;
	int row, col;

	void inputMatrix() 
	{
		for (int r = 0; r < row; r++)
		{
			for (int c = 0; c < col; c++)
				cin >> m[r][c];
		}
			
	}
	void setDimensions()
	{
		cout << "Unesite broj redova matrice " << endl;
		cin >> row;
		cout << "Unesite broj stupaca matrice " << endl;
		cin >> col;

		allocateMatrix();
	}


	void allocateMatrix() 
	{
		m = new float* [row];
		for (int r = 0; r < row; r++)
			m[r] = new float[col];
	}

	void fillWithRandomNumbers(int a, int b) 
	{
		for (int r = 0; r < row; r++ ) {
			for (int c = 0; c < col; c++) {
				m[r][c] = randomNumber(a, b);
			}
		}
	}

	void printMatrix() 
	{
		for (int r = 0; r < row; r++) 
		{
			for (int c = 0; c < col; c++) 
			{
				cout << setprecision(4) << right << setfill('0') << fixed << m[r][c] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}

	float randomNumber(int min, int max)
	{
		return  min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
	}

	void freeMatrix()
	{
		for (int r = 0; r < row; r++)
			delete[] m[r];
		delete[] m;
	}

	void add(Matrica m1)
	{
		if (row != m1.row || col != m1.col)
		{
			cout << "Matrice nisu istog tipa!" << endl;
			return;
		}

		for (int r = 0; r < row; r++)
		{
			for (int c = 0; c < col; c++)
				m[r][c] += m1.m[r][c];
		}
	}


	Matrica addTwoMatrices(Matrica m1, Matrica m2)
	{
		if (m1.row != m2.row || m1.col != m2.col)
		{
			cout << "Matrice nisu istog tipa! " << endl;
			//exit(0);
		}
		else
		{
			Matrica rslt;
			rslt.row = m1.row;
			rslt.col = m1.col;
			rslt.allocateMatrix();

			for (int r = 0; r < row; r++)
			{
				for (int c = 0; c < col; c++)
				{
					rslt.m[r][c] = m1.m[r][c] + m2.m[r][c];
				}
			}
			return rslt;
		}
	}

	void subtract(Matrica m1)
	{
		if (row != m1.row || col != m1.col)
		{
			cout << "Matrice nisu istog tipa!" << endl;
			return;
		}

		for (int r = 0; r < row; r++)
		{
			for (int c = 0; c < col; c++)
				m[r][c] -= m1.m[r][c];
		}
	}
	
	Matrica multiply(Matrica m1) 
	{
		if(col != m1.row)
		{ 
			cout << "Matrice nisu ulancane! " << endl;
			/*exit('0');*/
			
		}
		else
		{
			Matrica res;
			res.row = row;
			res.col = m1.col;
			res.allocateMatrix();

			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < m1.col; j++)
				{
					res.m[i][j] = 0;
					for (int k = 0; k < col; k++)
					{
						res.m[i][j] += m[i][k] * m1.m[k][j];
					}
				}
			}
			return res;
		}
	}


	Matrica transpond()
	{
		Matrica tran;
		tran.row = col;
		tran.col = row;
		tran.allocateMatrix();
		for (int r = 0; r < tran.row; r++)
		{
			for (int c = 0; c < tran.col; c++)
			{
				tran.m[r][c] = m[c][r];
			}
		}
		return tran;

	}

};
//
//struct matrica {
//	float** m;
//	int row, col;
//};


//matrica* allocation()
//{
//	matrica* mat = new matrica;
//	cout << "Unesite broj redova matrice " << endl;
//	cin >> mat->row;
//	cout << "Unesite broj stupaca matrice " << endl;
//	cin >> mat->col;
//
//	mat->m = new float* [mat->row];
//	for (int i = 0; i < mat->row; i++)
//		mat->m[i] = new float [mat->col];
//
//	return mat;
//}


int main()
{
	/*matrica* mat = allocation();*/
	srand(time(NULL));


	Matrica mat;
	mat.setDimensions();
	//mat.inputMatrix();
	mat.fillWithRandomNumbers(16, 54);
	cout << "mat" << endl;
	mat.printMatrix();
	//mat.freeMatrix();

	cout << "mat2" << endl;
	Matrica mat2;
	mat2.setDimensions();
	mat2.fillWithRandomNumbers(2, 7);
	mat2.printMatrix();
	mat2.add(mat);
	cout << "mat2 + mat" << endl;
	mat2.printMatrix();

	//mat.subtract(mat);
	//mat.printMatrix();

	cout << "mat3" << endl;
	Matrica mat3 = mat.multiply(mat2);
	mat3.printMatrix();

	cout << "mat4" << endl;
	Matrica mat4 = mat.transpond();
	mat4.printMatrix();

	Matrica mat7;
	mat7.setDimensions();
	mat7.inputMatrix();
    
	cout << "mat7" << endl;
	mat7.printMatrix();
	cout << "mat2" << endl;
	mat2.printMatrix();
	cout << "mat5" << endl;
	Matrica mat5 = mat7.addTwoMatrices(mat7, mat2);
	mat5.printMatrix();

	mat.freeMatrix();
	mat2.freeMatrix();
	mat3.freeMatrix();
	mat4.freeMatrix();

	



	
}
