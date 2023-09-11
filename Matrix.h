#ifndef LAB2_MATRIX_H
#define LAB2_MATRIX_H
#include <iostream>
#include "Vector.h"

class Vector;

class CSRMatrix {
private:
    int n;
    int m;
    int nnz;
    double* values;
    int* jptr;
    int* iptr;
public:
    CSRMatrix(int n, int m, int nnz);
    CSRMatrix(int n, int m, int nnz, const double* values, const int* jptr, const int* iptr);
    CSRMatrix(const CSRMatrix& matr);
    ~CSRMatrix();

    friend std::ostream& operator<< (std::ostream& out, const CSRMatrix& m);
    friend std::istream& operator>> (std::istream& in, CSRMatrix& m);
    Vector operator*(const Vector& v) const;
    CSRMatrix operator*(const double a) const;
    int n_cols() const;
    int n_rows() const;
    int n_nnz() const;
};

CSRMatrix operator*(double a, const CSRMatrix&);

#endif


