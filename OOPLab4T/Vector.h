#pragma once
#include <iostream>
#include <math.h>
using namespace std;

int vector_object_count = 0;

class ShortVector
{
	short* v;
	int num;   // default num=2
	int state = 0;
public:
	ShortVector() : ShortVector(2) { vector_object_count++; }
	ShortVector(size_t n) {
		if (n <= 0) n = 2;  // default num =2;
		num = n;
		v = new short[n];
		vector_object_count++;
		if (!v) {
			state = 2;
			return;
		}
		for (int i = 0; i < n; i++) {
			v[i] = 0;
		}
	}
	ShortVector(size_t n, short b) : ShortVector(n) {
		vector_object_count++;
		if (!v) {
			state = 2;
			return;
		}
		for (int i = 0; i < num; i++) v[i] = b;
	};
	ShortVector(size_t n, short* p) : ShortVector(n) {
		vector_object_count++;
		if (!v) {
			state = 2;
			return;
		}
		if (p != nullptr) for (int i = 0; i < num; i++) v[i] = p[i];
	};
	ShortVector(const ShortVector& s) {
		num = s.num;
		v = new short[num];
		vector_object_count++;
		if (!v) {
			state = 2;
			return;
		}
		state = s.state;
		for (int i = 0; i < num; i++)   v[i] = s.v[i];
	};
	ShortVector operator+(ShortVector s) const {
		if (num != s.num) {
			ShortVector result;
			result.state = 1;
			return result;
		}
		else {
			ShortVector result(num);
			for (int i = 0; i < num; i++) {
				result.v[i] = v[i] + s.v[i];
			}
			return result;
		}
	}
	ShortVector operator-(const ShortVector s) const {
		if (num != s.num) {
			ShortVector result;
			result.state = 1;
			return result;
		}
		else {
			ShortVector result(num);
			for (int i = 0; i < num; i++) {
				result.v[i] = v[i] - s.v[i];
			}
			return result;
		}
	};
	ShortVector operator*(unsigned char scalar) const {
		ShortVector result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] * scalar;
		}
		return result;
	};
	bool operator!=(const ShortVector s) const {
		if (num != s.num) {
			return true;
		}
		else {
			for (int i = 0; i < num; i++) {
				if (v[i] != s.v[i]) {
					return true;
				}
			}
			return false;
		}
	};
	bool operator==(const ShortVector s) const {
		if (num != s.num) {
			return false;
		}
		else {
			for (int i = 0; i < num; i++) {
				if (v[i] != s.v[i]) {
					return false;
				}
			}
			return true;
		}
	};
	ShortVector operator=(ShortVector s) {
		if (num != s.num)
		{
			delete[] v;
			num = s.num;
			v = new short[num];
			state = s.state;
		}
		for (int i = 0; i < num; i++)   v[i] = s.v[i];
		return *this;
	};
	~ShortVector() {
		delete[] v;
		vector_object_count--;
	}
	void set(int index, short x = 0) { if (index >= 0 && index <= num) v[index] = x; else state = 1; }
	short get(int index) { if (index >= 0 && index <= num) return v[index]; else state = 1; }
	void Output() {
		if (state == 1) {
			cout << "Index error";
			return;
		}
		if (state == 2)
		{
			cout << "Memory error";
			return;
		}
		if (num != 0) {
			for (int i = 0; i < num; i++) {
				cout << " v [ " << i << " ]   " << v[i] << '\t';
				cout << endl;
			}
		}
		else
		{
			cout << "Vector is empty";
		}
	};
	void Input() {
		int in_num = 0;
		do {
			cout << "Input size Vec\n";
			cin >> in_num;
		} while (in_num <= 0);
		if (num != in_num) {
			num = in_num;
			if (v) delete[] v;
			v = new short[num];
		}
		for (int i = 0; i < num; i++) {
			cout << " v [ " << i << " ]= "; cin >> v[i];
		}
	};
	ShortVector operator++() const {
		for (int i = 0; i < num; i++)
		{
			v[i]++;
		}
		return *this;
	}
	ShortVector operator--() {
		for (int i = 0; i < num; i++)
		{
			v[i]--;
		}
		return *this;
	}
	bool operator!() {
		return num ? true : false;
	}
	ShortVector operator~() {
		for (int i = 0; i < num; i++)
		{
			~v[i];
		}
		return *this;
	}
	ShortVector operator-() {
		for (int i = 0; i < num; i++)
		{
			v[i] = -v[i];
		}
		return *this;
	}
	ShortVector operator+=(ShortVector s) {
		ShortVector result;
		if (num != s.num) {
			result.state = 1;
		}
		else {
			ShortVector result(num);
			for (int i = 0; i < num; i++) {
				result.v[i] = v[i] + s.v[i];
			}
		}

		if (num != result.num)
		{
			delete[] v;
			num = result.num;
			v = new short[num];
			state = result.state;
		}
		for (int i = 0; i < num; i++)   v[i] = result.v[i];
		return *this;
	}
	ShortVector operator-=(ShortVector s) {
		ShortVector result;
		if (num != s.num) {
			result.state = 1;
		}
		else {
			ShortVector result(num);
			for (int i = 0; i < num; i++) {
				result.v[i] = v[i] - s.v[i];
			}
		}

		if (num != result.num)
		{
			delete[] v;
			num = result.num;
			v = new short[num];
			state = result.state;
		}
		for (int i = 0; i < num; i++)   v[i] = result.v[i];
		return *this;
	}
	ShortVector operator*=(short scalar) {
		ShortVector result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] * scalar;
		}

		if (num != result.num)
		{
			delete[] v;
			num = result.num;
			v = new short[num];
			state = result.state;
		}
		for (int i = 0; i < num; i++)   v[i] = result.v[i];
		return *this;
	}
	ShortVector operator/=(short scalar) {
		ShortVector result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] / scalar;
		}

		if (num != result.num)
		{
			delete[] v;
			num = result.num;
			v = new short[num];
			state = result.state;
		}
		for (int i = 0; i < num; i++)   v[i] = result.v[i];
		return *this;
	}
	ShortVector operator%=(short scalar) {
		ShortVector result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] % scalar;
		}

		if (num != result.num)
		{
			delete[] v;
			num = result.num;
			v = new short[num];
			state = result.state;
		}
		for (int i = 0; i < num; i++)   v[i] = result.v[i];
		return *this;
	}
	ShortVector operator|=(ShortVector s) {
		ShortVector result;
		if (num != s.num) {
			result.state = 1;
		}
		else {
			ShortVector result(num);
			for (int i = 0; i < num; i++) {
				result.v[i] = v[i] | s.v[i];
			}
		}

		if (num != result.num)
		{
			delete[] v;
			num = result.num;
			v = new short[num];
			state = result.state;
		}
		for (int i = 0; i < num; i++)   v[i] = result.v[i];
		return *this;
	}
	ShortVector operator^=(ShortVector s) {
		ShortVector result;
		if (num != s.num) {
			result.state = 1;
		}
		else {
			ShortVector result(num);
			for (int i = 0; i < num; i++) {
				result.v[i] = v[i] ^ s.v[i];
			}
		}

		if (num != result.num)
		{
			delete[] v;
			num = result.num;
			v = new short[num];
			state = result.state;
		}
		for (int i = 0; i < num; i++)   v[i] = result.v[i];
		return *this;
	}
	ShortVector operator&=(ShortVector s) {
		ShortVector result;
		if (num != s.num) {
			result.state = 1;
		}
		else {
			ShortVector result(num);
			for (int i = 0; i < num; i++) {
				result.v[i] = v[i] & s.v[i];
			}
		}

		if (num != result.num)
		{
			delete[] v;
			num = result.num;
			v = new short[num];
			state = result.state;
		}
		for (int i = 0; i < num; i++)   v[i] = result.v[i];
		return *this;
	}
	ShortVector operator/(unsigned char scalar) const {
		ShortVector result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] / scalar;
		}
		return result;
	};
	ShortVector operator%(unsigned char scalar) const {
		ShortVector result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] % scalar;
		}
		return result;
	};
	ShortVector operator|(unsigned char scalar) const {
		ShortVector result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] | scalar;
		}
		return result;
	};
	ShortVector operator^(unsigned char scalar) const {
		ShortVector result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] ^ scalar;
		}
		return result;
	};
	ShortVector operator&(unsigned char scalar) const {
		ShortVector result(num);
		for (int i = 0; i < num; i++) {
			result.v[i] = v[i] & scalar;
		}
		return result;
	};
	friend istream& operator>>(istream& is, ShortVector& sv);
	friend ostream& operator<<(ostream& os, const ShortVector& sv);
	short& operator[](size_t ind) {
		if (ind >= num) state = 1;
		return (ind < num) ? v[ind] : v[num - 1];
	}
	void* operator new(size_t size) {
		ShortVector temp();
		return &temp;
	}
	void operator delete(void* ptr) {
		ptr = nullptr;
	}
	ShortVector operator()(int value) {
		for (int i = 0; i < num; i++)
		{
			v[i] = value;
		}
		return *this;
	}
	bool operator>(const ShortVector s) const {
		if (num != s.num) {
			return false;
		}
		else {
			for (int i = 0; i < num; i++) {
				if (v[i] <= s.v[i]) {
					return false;
				}
			}
			return true;
		}
	};
	bool operator>=(const ShortVector s) const {
		if (num != s.num) {
			return false;
		}
		else {
			for (int i = 0; i < num; i++) {
				if (v[i] < s.v[i]) {
					return false;
				}
			}
			return true;
		}
	};
	bool operator<(const ShortVector s) const {
		if (num != s.num) {
			return false;
		}
		else {
			for (int i = 0; i < num; i++) {
				if (v[i] < s.v[i]) {
					return false;
				}
			}
			return true;
		}
	};
	void init(int n) {
		if (num != n) {
			if (v != nullptr) delete[] v;
			num = n;
			v = new short[n];
		}
		for (int i = 0; i < num; i++) 	v[i] = 0;
	}
	void init(int n, short b) {
		if (num != n) {
			if (v != nullptr) delete[] v;
			num = n;
			v = new short[n];
		}
		for (int i = 0; i < num; i++) 	v[i] = b;
	}
	int length() {
		return num;
	}
};
istream& operator>>(istream& is, ShortVector& sv)
{
	for (int i = 0; i < sv.num; i++)
	{
		is >> sv.v[i];
	}
	return is;
}

ostream& operator<<(ostream& os, const ShortVector& sv)
{
	for (int i = 0; i < sv.num; i++)
	{
		os << sv.v[i] << ' ';
	}
	return os;
}
