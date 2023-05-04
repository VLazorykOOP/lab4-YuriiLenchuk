#pragma once
#include "Vector.h"

class Matrix {
	ShortVector* data;
	int n;
	int m;
	int errorState = 0;
	static int num_matrix;
public:
	Matrix(){
		data = nullptr;
		n = 0; m = 0;
		errorState = 0;
	};
	Matrix(int size) {
		data = new ShortVector[size];
		n = size; m = size;
		num_matrix++;
		for(size_t i = 0; i < n; i++) data[i].init(size);
		if (data == nullptr) {
			errorState = 2;
			return;
		}
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				data[i][j] = 0;
			}
		}
	};
	Matrix(int n, int m) {
		data = new ShortVector[n];
		this->n = n; this->m = m;
		num_matrix++;
		for (size_t i = 0; i < n; i++) data[i].init(m);
		if (data == nullptr) {
			errorState = 2;
			return;
		}
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				data[i][j] = 0;
			}
		}
	};
	Matrix(int n, int m, short value) {
		data = new ShortVector[n];
		this->n = n; this->m = m;
		num_matrix++;
		for (size_t i = 0; i < n; i++) data[i].init(m);
		if (data == nullptr) {
			errorState = 2;
			return;
		}
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				data[i][j] = value;
			}
		}
	};
	Matrix(const Matrix& other) : Matrix(other.n, other.m) {
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				data[i][j] = other.data[i][j];
			}
		}
	};
	Matrix operator=(const Matrix other) {
		if (n != other.n || m != other.m) {
			delete[] data;
			n = other.n; m = other.m;
			data = new ShortVector [n];
			for (size_t i = 0; i < n; i++) data[i].init(m);
			errorState = other.errorState;
		}
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				data[i][j] = other.data[i][j];
			}
		}
		return *this;
	};
	~Matrix() {
		delete[] data;
	};

	void set(size_t i, size_t j, short value = 0) {
		data[i][j] = value;
	}
	short get(size_t i, size_t j) const {
		return data[i][j];
	};

	size_t rows_amount() {
		return n;
	}
	size_t cols_amount() {
		return m;
	}

	ShortVector operator[](size_t ind) {
		return data[ind];
	}

	Matrix operator+(const Matrix& other) {
		if (n != other.n || m != other.m) { Matrix result(1); errorState = 1; return result; }
		Matrix result(n);
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) result.data[i][j] = data[i][j] + other.data[i][j];
		return result;
	};
	Matrix operator-(const Matrix& other) {
		if (n != other.n || m != other.m) { Matrix result(1); errorState = 1; return result; }
		Matrix result(n);
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) result.data[i][j] = data[i][j] - other.data[i][j];
		return result;
	}
	Matrix operator*(Matrix other) {
		if (m != other.n) { Matrix result(1); errorState = 1; return result; }
		Matrix result(n);
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) {
			for (size_t k = 0; k < m; k++) result.data[i][j] += data[i][k] * other.data[k][j];
		}
		return result;
	}
	Matrix operator*(short scalar) {
		Matrix result(n);
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) result.data[i][j] = data[i][j] * scalar;
		return result;
	}
	Matrix operator%(const Matrix& other) {
		if (n != other.n || m != other.m) { Matrix result(1); errorState = 1; return result; }
		Matrix result(n);
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) result.data[i][j] = data[i][j] % other.data[i][j];
		return result;
	};

	bool operator==(const Matrix& other) const {
		if (n != other.n || m != other.m) { return false; }
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) if (data[i][j] != other.data[i][j]) return false;
		return true;
	};
	bool operator!=(const Matrix& other) const {
		if (n != other.n || m != other.m) { return true; }
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) if (data[i][j] != other.data[i][j]) return true;
		return false;
	};;
	bool operator>(const Matrix& other) const {
		if (n != other.n || m != other.m) { cout << "Size failure"; return false; }
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) if (data[i][j] <= other.data[i][j]) return false;
		return true;
	};
	bool operator>=(const Matrix& other) const {
		if (n != other.n || m != other.m) { cout << "Size failure"; return false; }
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) if (data[i][j] < other.data[i][j]) return false;
		return true;
	};

	void prsize_t() const {
		for (size_t i = 0; i < n; i++, cout << endl) for (size_t j = 0; j < m; j++) cout << data[i][j] << ' ';
	};
	void prsize_tError() const {
		if (errorState == 1)
		{
			cout << "index error";
		}
		else
		{
			cout << "memory error";
		}
	};
	Matrix operator++() {
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				data[i][j]++;
			}
		}
		return *this;
	}
	Matrix operator--() {
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				data[i][j]--;
			}
		}
		return *this;
	}
	bool operator!() {
		return (n && m) ? true : false;
	}
	Matrix operator~() {
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				~data[i][j];
			}
		}
		return *this;
	}
	Matrix operator-() {
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				data[i][j] = -data[i][j];
			}
		}
		return *this;
	}
	Matrix operator+(short scalar) {
		Matrix result(n, m);
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				result[i][j] = data[i][j] + scalar;
			}
		}
		return result;
	}
	Matrix operator-(short scalar) {
		Matrix result(n, m);
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				result[i][j] = data[i][j] - scalar;
			}
		}
		return result;
	}
	Matrix operator*(ShortVector other) {
		if (m != other.length()) { Matrix result(1); errorState = 1; return result; }
		Matrix result(n);
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) {
			for (size_t k = 0; k < m; k++) result.data[i][j] += data[i][k] * other[k];
		}
		return result;
	}
	Matrix operator/(Matrix other) {
		if (m != other.n) { Matrix result(1); errorState = 1; return result; }
		Matrix result(n);
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) {
			for (size_t k = 0; k < m; k++) result.data[i][j] += data[i][k] / other.data[k][j];
		}
		return result;
	}
	Matrix operator/(short scalar) {
		Matrix result(n, m);
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				result[i][j] = data[i][j] / scalar;
			}
		}
		return result;
	}
	Matrix operator%(short scalar) {
		Matrix result(n, m);
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				result[i][j] = data[i][j] % scalar;
			}
		}
		return result;
	}
	Matrix operator+=(const Matrix& other) {
		if (n != other.n || m != other.m) { Matrix result(1); errorState = 1; return result; }
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) data[i][j] += other.data[i][j];
	};
	Matrix operator+=(short scalar) {
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) data[i][j] +=scalar;
	};
	Matrix operator-=(const Matrix& other) {
		if (n != other.n || m != other.m) { Matrix result(1); errorState = 1; return result; }
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) data[i][j] -= other.data[i][j];
	};
	Matrix operator-=(short scalar) {
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) data[i][j] -= scalar;
	};
	Matrix operator*=(ShortVector other) {
		if (m != other.length()) { Matrix result(1); errorState = 1; return result; }
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) {
			for (size_t k = 0; k < m; k++) data[i][j] = data[i][k] * other[k];
		}
	}
	Matrix operator*=(Matrix other) {
		if (m != other.n) { Matrix result(1); errorState = 1; return result; }
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) {
			for (size_t k = 0; k < m; k++) data[i][j] = data[i][k] * other[k][j];
		}
	}
	Matrix operator*=(short scalar) {
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) {
			data[i][j] *= scalar;
		}
	}
	Matrix operator/=(ShortVector other) {
		if (m != other.length()) { Matrix result(1); errorState = 1; return result; }
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) {
			for (size_t k = 0; k < m; k++) data[i][j] = data[i][k] / other[k];
		}
	}
	Matrix operator/=(Matrix other) {
		if (m != other.n) { Matrix result(1); errorState = 1; return result; }
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) {
			for (size_t k = 0; k < m; k++) data[i][j] = data[i][k] / other[k][j];
		}
	}
	Matrix operator/=(short scalar) {
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) {
			data[i][j] /= scalar;
		}
	}
	Matrix operator%=(ShortVector other) {
		if (m != other.length()) { Matrix result(1); errorState = 1; return result; }
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) {
			for (size_t k = 0; k < m; k++) data[i][j] = data[i][k] % other[k];
		}
	}
	Matrix operator%=(Matrix other) {
		if (n != other.n && m != other.m) { Matrix result(1); errorState = 1; return result; }
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) data[i][j] %= other[i][j];
	}
	Matrix operator%=(short scalar) {
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) {
			data[i][j] %= scalar;
		}
	}
	Matrix operator|(const Matrix& other) {
		if (n != other.n || m != other.m) { Matrix result(1); errorState = 1; return result; }
		Matrix result(n);
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) result.data[i][j] = data[i][j] | other.data[i][j];
		return result;
	};
	Matrix operator|(short scalar) {
		Matrix result(n, m);
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) result[i][j] = data[i][j] | scalar;
		return result;
	}
	Matrix operator&(const Matrix& other) {
		if (n != other.n || m != other.m) { Matrix result(1); errorState = 1; return result; }
		Matrix result(n);
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) result.data[i][j] = data[i][j] & other.data[i][j];
		return result;
	};
	Matrix operator&(short scalar) {
		Matrix result(n, m);
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) result[i][j] = data[i][j] & scalar;
		return result;
	}
	Matrix operator^(const Matrix& other) {
		if (n != other.n || m != other.m) { Matrix result(1); errorState = 1; return result; }
		Matrix result(n);
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) result.data[i][j] = data[i][j] ^ other.data[i][j];
		return result;
	};
	Matrix operator^(short scalar) {
		Matrix result(n, m);
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) result[i][j] = data[i][j] ^ scalar;
		return result;
	}
	Matrix operator>>=(Matrix other) {
		if (n != other.n && m != other.m) { Matrix result(1); errorState = 1; return result; }
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) data[i][j] >>= other[i][j];
	}
	Matrix operator>>=(short scalar) {
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) data[i][j] >>= scalar;
	}
	Matrix operator<<=(Matrix other) {
		if (n != other.n && m != other.m) { Matrix result(1); errorState = 1; return result; }
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) data[i][j] <<= other[i][j];
	}
	Matrix operator<<=(short scalar) {
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) data[i][j] <<= scalar;
	}
	Matrix operator|=(Matrix other) {
		if (n != other.n && m != other.m) { Matrix result(1); errorState = 1; return result; }
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) data[i][j] |= other[i][j];
	}
	Matrix operator|=(short scalar) {
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) data[i][j] |= scalar;
	}
	Matrix operator&=(Matrix other) {
		if (n != other.n && m != other.m) { Matrix result(1); errorState = 1; return result; }
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) data[i][j] &= other[i][j];
	}
	Matrix operator&=(short scalar) {
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) data[i][j] &= scalar;
	}
	Matrix operator^=(Matrix other) {
		if (n != other.n && m != other.m) { Matrix result(1); errorState = 1; return result; }
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) data[i][j] ^= other[i][j];
	}
	Matrix operator^=(short scalar) {
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) data[i][j] ^= scalar;
	}
	bool operator<(const Matrix& other) const {
		if (n != other.n || m != other.m) { cout << "Size failure"; return false; }
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) if (data[i][j] >= other.data[i][j]) return false;
		return true;
	};
	bool operator<=(const Matrix& other) const {
		if (n != other.n || m != other.m) { cout << "Size failure"; return false; }
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) if (data[i][j] > other.data[i][j]) return false;
		return true;
	};
	Matrix operator()(short value) {
		for (size_t i = 0; i < n; i++) for (size_t j = 0; j < m; j++) data[i][j] = value;
	}
	void* operator new(size_t size) {
		Matrix temp(size);
		return &temp;
	}
	void operator delete(void* ptr) {
		ptr = nullptr;
	}
	friend istream& operator>>(istream& is, Matrix& m);
	friend ostream& operator<<(ostream& os, const Matrix& svm;
};

istream& operator>>(istream& is, Matrix& m)
{
	for (size_t i = 0; i < m.n; i++) for (size_t i = 0; i < m.m; i++) is >> m.data[i][j];
	return is;
}

ostream& operator<<(ostream& os, const Matrix& m)
{
	for (size_t i = 0; i < m.n; i++, cout << endl) for (size_t i = 0; i < m.m; i++) os << m.data[i][j] << ' ';
	return os;
}