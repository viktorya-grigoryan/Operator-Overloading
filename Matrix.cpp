#define _CRT_SECURE_NO_WARNINGS
#include "Matrix.h"
#include "Vector.h"
#include "Exception.h"

CSRMatrix::CSRMatrix(const int n, const int m, const int nnz, const double* p_values,
    const int* column_indexes, const int* row_indexes)
    : n(n), m(m), nnz(nnz), values(new double[nnz]), jptr(new int[nnz]), iptr(new int[n + 1]) {
    for (int i = 0; i < nnz; i++)
        values[i] = p_values[i];
    for (int i = 0; i < nnz; i++)
        jptr[i] = column_indexes[i];
    for (int i = 0; i < n + 1; i++)
        iptr[i] = row_indexes[i];
}

CSRMatrix::CSRMatrix(const CSRMatrix& matr) {
    n = matr.n;
    m = matr.m;
    nnz = matr.nnz;
    values = new double[nnz];
    jptr = new int[nnz];
    iptr = new int[n + 1];
    for (int i = 0; i < nnz; i++)
        values[i] = matr.values[i];
    for (int i = 0; i < nnz; i++)
        jptr[i] = matr.jptr[i];
    for (int i = 0; i < n + 1; i++)
        iptr[i] = matr.iptr[i];
}

CSRMatrix::CSRMatrix(const int n, const int m, const int nnz)
    : n(n), m(m), nnz(nnz), values(new double[nnz]), jptr(new int[nnz]), iptr(new int[n + 1]) {};

CSRMatrix::~CSRMatrix() {
    delete[] values;
    delete[] jptr;
    delete[] iptr;
}

Vector CSRMatrix::operator*(const Vector& v) const {
    if (v.size_vec() != m)
        throw IncompatibleDimException("Different sizes");
    Vector res(n);
    for (int i = 0; i < n; i++) {        
        for (int j = iptr[i]; j < iptr[i + 1]; j++) {
            res[i] += v[jptr[j]] * values[j];
        }
    }
    return res;
}


//!!! данный оператор для печати полной матрицы,
//!!! но БЕЗ выделения памяти под всю матрицу.
std::ostream& operator<<(std::ostream& out, const CSRMatrix& m) {
    int j = 0;
    int c;
    double* mas = new double[m.n];
    for (int t = 0; t < m.n; t++) {
        c = m.iptr[t + 1] - m.iptr[t];
        for (int p = 0; p < m.n; p++) {
            mas[p] = 0;
        }
        for (int k = 0; k < m.n; k++) {
            for (int l = j; l < j + c; l++) {
                if (k == (m.jptr[l])) {
                    mas[k] = m.values[l];
                }
            }
            out << (mas[k]) << " ";
        }
        j += (c);
        std::cout << "\n";
    }
    delete[]mas;
    return out;
}

std::istream& operator>>(std::istream& in, CSRMatrix& other) {
    int n1, nnz1;
    std::cout << "Input size of matrix:";
    std::cin >> n1;
    std::cout << "Input amount of not zero elements of matrix:";
    std::cin >> nnz1;
    if (n1 != other.n) {
        delete[] other.iptr;
        other.iptr = new int[n1 + 1];
        other.n = n1;
    }
    if (other.nnz != nnz1) {
        delete[] other.values;
        delete[] other.jptr;
        other.values = new double[nnz1];
        other.jptr = new int[nnz1];
        other.nnz = nnz1;
    }
    std::cout << "Enter values array (" << other.nnz << "): ";
    for (int i = 0; i < other.nnz; i++) {
        in >> other.values[i];
    }
    in.get();
    std::cout << "Enter column_indexes array (" << other.nnz << "): ";
    for (int i = 0; i < other.nnz; i++) {
        in >> other.jptr[i];
    }
    in.get();
    std::cout << "Enter row_indexes array (" << other.nnz << "): ";
    other.iptr[0] = 0;
    for (int i = 0; i < other.n + 1; i++) {
        in >> other.iptr[i];
    }
    return in;
}


CSRMatrix CSRMatrix::operator*(const double a) const {
    CSRMatrix matr(*this);
    for (int i = 0; i < nnz; i++) {
        matr.values[i] *= a;
    }
    return matr;
}



CSRMatrix operator*(double a, const CSRMatrix& m) {
    return m * a;
}

int CSRMatrix::n_cols() const {
    return m;
}

int CSRMatrix::n_rows() const {
    return n;
}

int CSRMatrix::n_nnz() const {
    return nnz;
}


