#include "Matrices.h"

namespace Matrices
{

	Matrix::Matrix(int _rows, int _cols)
	{
		rows = _rows;
		cols = _cols;
		
		a.resize(rows);
		
		for(int i = 0; i < rows; i++)
		{
			a[i].resize(cols,0);
		}


		
	}

	



	Matrix operator+(const Matrix& a, const Matrix& b)
	{
		int aRows = a.getRows();
		int aCols = a.getCols();
		int bRows = b.getRows();
		int bCols = b.getCols();

		if (aRows != bRows || aCols != bCols) {
			throw std::invalid_argument("Matrix dimensions are not compatible for addition");
		}

		Matrix result(aRows, aCols);

		for (int i = 0; i < aRows; ++i) {
			for (int j = 0; j < aCols; ++j) {
				result(i, j) = a(i, j) + b(i, j);
			}
		}

		return result;
	}

	Matrix operator*(const Matrix& a, const Matrix& b)
	{
		int aRows = a.getRows();
		int aCols = a.getCols();
		int bRows = b.getRows();
		int bCols = b.getCols();

		if (aCols != bRows) {
			throw invalid_argument("Error: dimensions must agree");
		}

		Matrix result(aRows, bCols);  

		for (int i = 0; i < aRows; ++i) {
			for (int j = 0; j < bCols; ++j) {
				double sum = 0.0;
				for (int k = 0; k < aCols; ++k) {
					sum += a(i, k) * b(k, j);
				}
				result(i, j) = sum;
			}
		}

		return result;
	}


	ostream& operator<<(ostream& os, const Matrix& a)
	{
		for (int i = 0; i < a.getRows(); i++) 
		{
			for (int j = 0; j < a.getCols(); j++) 
			{
				os << setw(10) << a(i, j) << setw(10);
			}
			os << "\n\n";
		}
		return os;
	}

	bool operator==(const Matrix& a, const Matrix& b)
	{
		int curcols = a.getCols();
		int currows = a.getRows();

		if (b.getCols() != curcols || b.getRows() != currows)
		{
			return false;
		}


		for (int i = 0; i < curcols; i++)
		{
			for (int j = 0; j < currows; j++)
			{
				if (abs(a(j, i) - b(j, i)) > 0.001)
				{
					return false;
				}
			}
		}

		return true;
	}

	bool operator!=(const Matrix& a, const Matrix& b)
	{
		if (a == b)
		{
			return false;
		}
		else
		{
			return true;
		}
	}




}