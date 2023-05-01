#pragma once
#include "Vector.h"

int matrix_object_count = 0;
class Matrix {
	ShortVector* data;
	int n;
	int errorState = 0;
public:
	Matrix(){
		data = nullptr;
		n = 0;
		errorState = 0;
	};
	Matrix(int size) {
		data = new ShortVector[3, size];
		n = size;
		matrix_object_count++;
		if (data == nullptr) {
			errorState = 2;
			return;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				data[i][j] = 0;
			}
		}
	};
	Matrix(int size, short value) {
		data = new ShortVector[3, size];
		n = size;
		matrix_object_count++;
		if (data == nullptr) {
			errorState = 2;
			return;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				data[i][j] = value;
			}
		}
	};
	Matrix(int size, short value1, short value2, short value3) {
		data = new ShortVector[3, size];
		n = size;
		matrix_object_count++;
		if (data == nullptr) {
			errorState = 2;
			return;
		}
		for (int i = 0; i < n; i++)
		{
			data[i][0] = value1;
			data[i][1] = value2;
			data[i][2] = value3;
		}
	};
	Matrix(const Matrix& other) : Matrix(other.n) {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				data[i][j] = other.data[i][j];
			}
		}
	};
	Matrix& operator=(const Matrix other) {
		if (n != other.n) {
			delete[] data;
			n = other.n;
			data = new ShortVector [3, n];
			errorState = other.errorState;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 3; j++)
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
		if (n != other.n) { Matrix result(1); errorState = 1; return result; }
		Matrix result(n);
		for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) result.data[i][j] = data[i][j] + other.data[i][j];
		return result;
	};
	Matrix operator-(const Matrix& other) {
		if (n != other.n) { Matrix result(1); errorState = 1; return result; }
		Matrix result(n);
		for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) result.data[i][j] = data[i][j] - other.data[i][j];
		return result;
	}
	Matrix operator*(Matrix other) {
		if (other.n != 3) { Matrix result(1); errorState = 1; return result; }
		Matrix result(n);
		for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) result.data[i][j] += data[i][k] * other.data[k][j];
		}
		return result;
	}
	Matrix operator*(short scalar) {
		Matrix result(n);
		for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) result.data[i][j] = data[i][j] * scalar;
		return result;
	}

	bool operator==(const Matrix& other) const {
		if (n != other.n) { return false; }
		for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) if (data[i][j] != other.data[i][j]) return false;
		return true;
	};
	bool operator!=(const Matrix& other) const {
		if (n != other.n) { return true; }
		for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) if (data[i][j] != other.data[i][j]) return true;
		return false;
	};;
	bool operator>(const Matrix& other) const {
		if (n != other.n) { cout << "Size failure"; return false; }
		for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) if (data[i][j] <= other.data[i][j]) return false;
		return true;
	};
	bool operator>=(const Matrix& other) const {
		if (n != other.n) { cout << "Size failure"; return false; }
		for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) if (data[i][j] < other.data[i][j]) return false;
		return true;
	};

	void print() const {
		for (int i = 0; i < n; i++, cout << endl) for (int j = 0; j < 3; j++) cout << data[i][j] << ' ';
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