#include <iostream>
#include "Vector.h"
#include "Matrix.h"
using namespace std;
int main()
{
	try {
		Vector v1(4, 1);
		Vector v2(4, 2);
		Vector v3(4, 3);
		Vector v4(4, 4);
		Vector v5(4, 5);
		Vector res(4, 10);
		cout << "VECTOR" << endl;
		cout << "v1 = " << v1 << endl;
		cout << "v2 = " << v2 << endl;
		cout << "v3 = " << v3 << endl;
		cout << "v4 = " << v4 << endl;
		cout << "v5 = " << v5 << endl << endl;
		cout << "v1 + v2 = " << v1 + v2 << endl;
		cout << "v5 - v3 = " << v5 - v3 << endl;
		cout << "v2 * v4 = " << v2 * v4 << endl;
		cout << "-v2 = " << -v2 << endl;
		cout << "v3 - (v4 * 3) + v5 = " << v3 - (v4 * 3) + v5 << endl;
		cout << "res = 2 * v5 = " << 2 * v5 << endl;
		res += v1;
		cout << "res += v1 => res = " << res << endl;
		cout << "Size of v5 = " << v5.size_vec() << endl;
		cout << "Lenght of res = " << res.lenght() << endl << endl;
		cout << "MATRIX" << endl;
		double values[] = { 1, 3, 5, 2, 4 };
		int jptr[] = { 0, 1, 1, 1, 2 };
		int iptr[] = { 0, 2, 3, 5 };
		int nnz = 5;
		int n = 3;
		int m = 3;
		CSRMatrix ma(n, m, nnz, values, jptr, iptr);

		v1 = Vector(3, 3);
		v2 = Vector(3, 6);
		v3 = Vector(3, 9);
		cout << "Matrix:\n" << ma << endl;
		cout << "v1 = " << v1 << endl;
		cout << "Matrix * v1 = " << ma * v1 << endl << endl;
		cout << "Matrix * 3: " << endl << (ma * 3) << endl;
		cout << "v1 = " << v1 << endl;
		cout << "v2 = " << v2 << endl;
		cout << "v3 = " << v3 << endl;
		cout << "matrix * (v1 - 2 * v2) + v3 * 3 = " << ma * (v1 - 2 * v2) + v3 * 3 << endl;

	}
	catch (exception& e) {
		cout << e.what();
	}
	return 0;
}




