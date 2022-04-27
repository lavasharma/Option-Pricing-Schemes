#include "Matrix.h"
#include <cmath>

using namespace std;

Vector operator*(const Matrix &C, const Vector &V)  // Matrix and Vector Multiply
{
    int d = (int)C.size(); // Size of Matrix
    Vector W(d); //to hold final values
    for(int i = 0; i < d ; i++)
    {
        W[i] = 0.0;
        for(int j = 0; j < d; j++)
        {
            W[j] += C[i][j]*V[j];
        }
    }
    return W;
}

Vector operator*(const double &a, const Vector &V)    // Scalar and Vector Multiply
{
    int d = (int)V.size();
    Vector U(d);
    for(int i = 0; i < d; i++)
    {
        U[i] = a * V[i];
    }
    return U;
}
Vector operator*(const Vector &V, const Vector &W)    // Vector and Vector Multiply Vector Product
{
    int d = (int)V.size();
    Vector U(d);
    for(int i = 0; i < d; i++)
    {
        U[i] = V[i] * W[i];
    }
    return U;
}

Vector operator+(const double &a, const Vector &V)
{
    int d = (int)V.size();
    Vector U(d);
    for(int i = 0; i < d; i++)
    {
        U[i] = a + V[i];
    }
    return U;
}

Vector operator+(const Vector &V, const Vector &W)
{
    int d = (int)V.size();
    Vector U(d);
    for(int i = 0; i < d; i++)
    {
        U[i] = V[i] + W[i];
    }
    return U;
}

Vector exp(const Vector &V)
{
    int d = (int)V.size();
    Vector U(d);
    for(int i = 0; i < d; i++)
    {
        U[i] = std::exp(V[i]);
    }
    return U;
}

Vector operator/(const Vector &V, const Vector &W)
{
    int d = (int)V.size();
    Vector U(d);
    for(int i = 0; i < d; i++)
    {
        U[i] = V[i] / W[i];
    }
    return U;
}

double operator^(const Vector &V, const Vector &W)
{
    double sum = 0.0;
    int d = (int)V.size();
    for(int j = 0; j < d ; j++)
    {
        sum += V[j]*W[j];
    }
    return sum;
}

ostream& operator<<(ostream& out, Vector& V)
{
    for (Vector::iterator itr = V.begin(); itr != V.end(); itr++)
        out << *itr << "   ";
    out << endl;
    return out;
}

ostream& operator<<(ostream& out, Matrix& W)
{
    for (Matrix::iterator itr = W.begin(); itr != W.end(); itr++)
        out << *itr;    // Use ostream & operator<<(ostream & out, Vector & V)
    out << endl;
    return out;
}

Matrix operator*(const Matrix &M, const Matrix &N)
{
    int d = (int) M.size();
    Matrix Output(d);
    for(int i = 0; i<d; i++) Output.resize(i);

    for(int i = 0; i < d; i++)
    {
        for(int j = 0; j < d ; j++ )
        {
            for(int k = 0; k < d; k++)
            {
                Output[i][j] += M[i][k] * N[k][j];
            }
            //cout << Output[i][j]  << endl;
        }
    }
    return Output;
}


