#ifndef LAB2_VECTOR_H
#define LAB2_VECTOR_H
#include <iostream>
#include "Matrix.h"
#pragma once
#include <iostream>
#include <math.h>

class Vector
{
	int size;
	double* m_elems = nullptr;

public:
	Vector(int _size = 0, double num = 0);
	Vector(const Vector& vec);
	~Vector();

	double lenght() const;

	Vector operator+ (const Vector& p_vec);

	Vector operator- (const Vector& p_vec);

	Vector& operator= (const Vector& p_vec);

	Vector& operator+= (const Vector& p_vec);

	Vector& operator-= (const Vector& p_vec);

	Vector operator*(const double a) const;

	double operator*(const Vector& p_vec) const;

	Vector operator-();

	Vector& operator+();

	double& operator[](int p_ind);

	const double& operator[](int p_ind) const;

	int size_vec() const;

	explicit operator double* () {
		return m_elems;
	}

	friend std::ostream& operator<<(std::ostream& out, const Vector& vec);

	friend std::ostream& operator>>(std::ostream& in, const Vector& vec);
};

Vector operator* (double a, const Vector& vec);

#endif