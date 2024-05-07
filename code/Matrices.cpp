#include "Matrices.h"


namespace Matrices
{
    Matrix::Matrix(int _rows, int _cols)
    {
        a.resize(_rows, { 0 });
        for (int i = 0; i < a.size(); i++)
        {
            a.at(i).resize(_cols, 0);
        }
        rows = _rows;
        cols = _cols;
    }

    ///Add each corresponding element.
    ///usage:  c = a + b;
    Matrix operator+(const Matrix& a, const Matrix& b)
    {
        if (a.getCols() == b.getCols() && a.getRows() == b.getRows())
        {
            Matrix c(a.getRows(), a.getCols());
            for (int i = 0; i < a.getRows(); i++)
            {
                for (int j = 0; j < a.getCols(); j++)
                {
                    c(i, j) = a(i, j) + b(i, j);
                }
            }
            return c;
        }
        else
        {
            throw runtime_error("Error: dimensions must agree");
        }

    }

    ///Matrix multiply.  See description.
    ///usage:  c = a * b;
    Matrix operator*(const Matrix& a, const Matrix& b)
    {
        if (a.getCols() == b.getRows())
        {
            Matrix c(a.getRows(), b.getCols());
            for (int i = 0; i < a.getRows(); i++)
            {
                for (int k = 0; k < b.getCols(); k++)
                {
                    for (int j = 0; j < a.getCols(); j++)
                    {
                        c(i, k) += a(i, j) * b(j, k);
                    }
                }
            }
            return c;
        }
        else
        {
            throw runtime_error("Error: dimensions must agree");
        }

    }

    ///Matrix comparison.  See description.
    ///usage:  a == b
    bool operator==(const Matrix& a, const Matrix& b)
    {
        if (a.getCols() == b.getCols() && a.getRows() == b.getRows())
        {
            for (int i = 0; i < a.getRows(); i++)
            {
                for (int j = 0; j < a.getCols(); j++)
                {
                    if (a(i, j) != b(i, j))
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    ///Matrix comparison.  See description.
    ///usage:  a != b
    bool operator!=(const Matrix& a, const Matrix& b)
    {
        return !(a == b);
    }

    ///Output matrix.
    ///Separate columns by ' ' and rows by '\n'
    ostream& operator<<(ostream& os, const Matrix& a)
    {
        for (int i = 0; i < a.getRows(); i++)
        {
            for (int j = 0; j < a.getCols(); j++)
            {
                os << a(i, j) << ' ';
            }
            os << '\n';
        }
        return os;

    }


    RotationMatrix::RotationMatrix(double theta) : Matrix(2,2)
    {
        a.at(0).at(0) = cos(theta);
        a.at(1).at(0) = sin(theta);
        a.at(0).at(1) = -sin(theta);
        a.at(1).at(1) = cos(theta);
    }

    ScalingMatrix::ScalingMatrix(double scale) : Matrix(2, 2)
    {
        a.at(0).at(0) = scale;
        a.at(1).at(0) = 0;
        a.at(0).at(1) = 0;
        a.at(1).at(1) = scale;
    }

    TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols) : Matrix(2,nCols)
    {
        for (int i = 0; i < nCols; i++)
        {
            a.at(0).at(i) = xShift;
            a.at(1).at(i) = yShift;
        }
    }


}