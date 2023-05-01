#pragma once
#include "Vector.h"

int matrix_object_count = 0;
class Matrix {
	ShortVector* data;
	int n;
	int m;
	int errorState = 0;
public:
	Matrix(){
		data = nullptr;
		n = 0;
		errorState = 0;
	};
	Matrix(int size) {
		data = new ShortVector[size];
		n = size; m = size;
		matrix_object_count++;
		for(int i = 0; i < n; i++) data[i].init(size);
		if (data == nullptr) {
			errorState = 2;
			return;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				data[i][j] = 0;
			}
		}
	};
	Matrix(int n, int m) {
		data = new ShortVector[n];
		this->n = n; this->m = m;
		matrix_object_count++;
		for (int i = 0; i < n; i++) data[i].init(m);
		if (data == nullptr) {
			errorState = 2;
			return;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				data[i][j] = 0;
			}
		}
	};
	Matrix(int n, int m, short value) {
		data = new ShortVector[n];
		this->n = n; this->m = m;
		matrix_object_count++;
		for (int i = 0; i < n; i++) data[i].init(m);
		if (data == nullptr) {
			errorState = 2;
			return;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				data[i][j] = value;
			}
		}
	};
	Matrix(const Matrix& other) : Matrix(other.n, other.m) {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				data[i][j] = other.data[i][j];
			}
		}
	};
	Matrix& operator=(const Matrix other) {
		if (n != other.n || m != other.m) {
			delete[] data;
			n = other.n; m = other.m;
			data = new ShortVector [n];
			for (int i = 0; i < n; i++) data[i].init(m);
			errorState = other.errorState;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				data[i][j] = other.data[i][j];
			}
		}
		return *this;
	};
	~Matrix() {
		delete[] data;
	};

	void set(int i, int j, short value = 0) {
		data[i][j] = value;
	}
	short get(int i, int j) const {
		return data[i][j];
	};


	Matrix operator+(const Matrix& other) {
		if (n != other.n || m != other.m) { Matrix result(1); errorState = 1; return result; }
		Matrix result(n);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) result.data[i][j] = data[i][j] + other.data[i][j];
		return result;
	};
	Matrix operator-(const Matrix& other) {
		if (n != other.n || m != other.m) { Matrix result(1); errorState = 1; return result; }
		Matrix result(n);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) result.data[i][j] = data[i][j] - other.data[i][j];
		return result;
	}
	Matrix operator*(Matrix other) {
		if (m != other.n) { Matrix result(1); errorState = 1; return result; }
		Matrix result(n);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
			for (int k = 0; k < 3; k++) result.data[i][j] += data[i][k] * other.data[k][j];
		}
		return result;
	}
	Matrix operator*(short scalar) {
		Matrix result(n);
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) result.data[i][j] = data[i][j] * scalar;
		return result;
	}

	bool operator==(const Matrix& other) const {
		if (n != other.n || m != other.m) { return false; }
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (data[i][j] != other.data[i][j]) return false;
		return true;
	};
	bool operator!=(const Matrix& other) const {
		if (n != other.n || m != other.m) { return true; }
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (data[i][j] != other.data[i][j]) return true;
		return false;
	};;
	bool operator>(const Matrix& other) const {
		if (n != other.n || m != other.m) { cout << "Size failure"; return false; }
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (data[i][j] <= other.data[i][j]) return false;
		return true;
	};
	bool operator>=(const Matrix& other) const {
		if (n != other.n || m != other.m) { cout << "Size failure"; return false; }
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (data[i][j] < other.data[i][j]) return false;
		return true;
	};

	void print() const {
		for (int i = 0; i < n; i++, cout << endl) for (int j = 0; j < m; j++) cout << data[i][j] << ' ';
	};
	void printError() const {
		if (errorState == 1)
		{
			cout << "index error";
		}
		else
		{
			cout << "memory error";
		}
	};

};