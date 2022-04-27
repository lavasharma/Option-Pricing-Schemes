#pragma once

#include <vector>
#include <iostream>

using namespace std;
typedef vector<double> Vector;
typedef vector<Vector> Matrix;

Vector operator*(const Matrix &C, const Vector &V);  // Matrix and Vector Multiply
Vector operator*(const double &a, const Vector &V);   // Scalar and Vector Multiply
Vector operator*(const Vector &V, const Vector &W);   // Vector and Vector Multiply Vector Product


Vector operator+(const double &a, const Vector &V);
Vector operator+(const Vector &V, const Vector &W);

Vector exp(const Vector &V);
double operator^(const Vector &V, const Vector &W);



ostream& operator<<(ostream &out,Vector &V); // Overload cout for Vector
ostream& operator<<(ostream &out,Matrix &C); // Overload cout for Matrix

Matrix operator*(const Matrix &M, const Matrix &N); // Matrix Multiply
Vector operator/(const Vector &V, const Vector &W);



