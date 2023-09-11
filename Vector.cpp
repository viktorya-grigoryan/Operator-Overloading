#include "Vector.h"
#include "Matrix.h"
#include "Exception.h"


Vector::Vector(int _size, double num) {
	size = _size;
	m_elems = new double[size];
	for (int i = 0; i < size; i++) {
		m_elems[i] = num;
	}
}

Vector::Vector(const Vector& vec) {
	size = vec.size;
	m_elems = new double[size];
	for (int i = 0; i < size; i++) {
		m_elems[i] = vec.m_elems[i];
	}
}

Vector::~Vector() {
	delete[] m_elems;
}

Vector Vector::operator+(const Vector& p_vec)
{
	if (size != p_vec.size)
		throw IncompatibleDimException("Can't sum vectors, different sizes");
	Vector res(size);
	for (int i = 0; i < size; i++) {
		res.m_elems[i] = m_elems[i] + p_vec.m_elems[i];
	}
	return res;
}

Vector Vector::operator-(const Vector& p_vec)
{
	if (size != p_vec.size)
		throw IncompatibleDimException("Can't substract vectors, different sizes");
	Vector res(size);
	for (int i = 0; i < size; i++) {
		res.m_elems[i] = m_elems[i] - p_vec.m_elems[i];
	}
	return res;
}

Vector& Vector::operator= (const Vector& p_vec) {
	if (this == &p_vec) {
		return *this;
	}
	if (size != p_vec.size) {
		delete[] m_elems;
		m_elems = new double[p_vec.size];
		size = p_vec.size;
	}
	for (int i = 0; i < size; i++) {
		m_elems[i] = p_vec.m_elems[i];
	}
	return (*this);
}


double Vector::lenght() const {
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += (m_elems[i] * m_elems[i]);
	}
	return std::sqrt(sum);
}

int Vector::size_vec() const {
	return size;
}

Vector& Vector::operator+=(const Vector& p_vec) {
	if (size != p_vec.size) {
		throw IncompatibleDimException("Can't sum vectors, different sizes");
	}
	for (int i = 0; i < size; i++) {
		m_elems[i] += p_vec.m_elems[i];
	}
	return (*this);
}

Vector& Vector::operator-=(const Vector& p_vec) {
	if (size != p_vec.size) {
		throw IncompatibleDimException("Can't substract vectors, different sizes");
	}
	for (int i = 0; i < size; i++) {
		m_elems[i] -= p_vec.m_elems[i];
	}
	return (*this);
}

Vector Vector::operator-() {
	Vector vec(size, 1);
	for (int i = 0; i < size; i++) {
		vec.m_elems[i] = (-1) * m_elems[i];
	}
	return (vec);
}

Vector& Vector::operator+() {
	return *(this);
}

double Vector::operator*(const Vector& v) const {
	if (size != v.size)
		throw IncompatibleDimException("Can't dot vectors, different sizes");
	double res = 0;
	for (int i = 0; i < size; i++) {
		res += (v[i] * m_elems[i]);
	}
	return res;
}


Vector Vector::operator*(const double a) const {
	Vector res(size);
	for (int i = 0; i < size; i++) {
		res.m_elems[i] = m_elems[i] * a;
	}
	return res;
}

std::ostream& operator<<(std::ostream& out, const Vector& vec) {
	out << "{ ";
	for (int i = 0; i < vec.size; i++) {
		out << vec.m_elems[i] << " ";
	}
	out << "}";
	return out;
}

std::ostream& operator>>(std::ostream& in, Vector& vec) {
	int n;
	std::cout << "Input size of vector:" << std::endl;
	std::cin >> n;
	std::cout << "Input vector:" << std::endl;
	if (n != vec.size_vec()) {
		Vector res(n);
		for (int i = 0; i < n; i++) {
			std::cin >> res[i];
		}
		vec = res;
	}
	else {
		for (int i = 0; i < vec.size_vec(); i++) {
			std::cin >> vec[i];
		}
	}
	return in;
}

const double& Vector::operator[](int p_ind) const {
	if (p_ind < 0 || p_ind >= size) {
		throw OutOfRangeException("Index is out of range");
	}
	return m_elems[p_ind];
}

double& Vector::operator[](int p_ind) {
	if (p_ind < 0 || p_ind >= size) {
		throw OutOfRangeException("Index is out of range");
	}
	return m_elems[p_ind];
}

Vector operator*(double a, const Vector& vec) {
	int size = vec.size_vec();
	Vector res(size);
	for (int i = 0; i < size; i++) {
		res[i] = vec[i] * a;
	}
	return res;
}

