#include <iostream>
#include "Lab4Exmaple.h"
#include "Vector.h"
#include "Matrix.h"
#include "Associated Class.h"
#include <map>
#include <string>

using namespace std;

void mainExample1() {

	/// Задано : A,B,C,D,F  -  Вектори цілих чисел 
	///         a,b,c - задані цілі числа.
	/// Обчислити вираз : F = A+B-B*c+C/b+D*a        
	cout << "Input array size: ";
	int size = cin.get(), a, b, c;
	ShortVector A(size, 1), B(size, 2), C(size, 3), D(size, 4), F(size, 5);
	cout << "Input a, b, c: ";
	cin >> a >> b >> c;
	cout << " A  = \n" << A;
	cout << " B  = \n" << B;
	cout << " C  = \n" << C;
	cout << " D  = \n" << D;

	F += A + B - B * c + C / b + D * a;

	
	cout << " \n F = \n" << F;
	cout << " ++A = \n" << ++A;
}


void mainExample2() {
	ContactList list;
	list("Ivan", "qwe@famil.com", "1234567890");
	list("Andrii", "123@famil.com", "0987654321");
	cin >> list;
	cout << list;
}

/// Задано : A,B,C,D,F  -  Матриці цілих чисел
///          a,b,c  -  Вектори цілих чисел 
///          _a, _b, _c - цілих числа.
/// Обчислити вираз : F = A+B*_a-B*_c+C/_b; 
///                   A = F*a + D*b     
void mainExample3() {
	Matrix A(5, 2, 1), B(5, 3, 2), C(5, 4, 3), D(5, 5, 4), F(5, 6, 5);
	ShortVector a(5, 1), b(5, 2), c(5, 3);
	short _a = 2, _b = 3, _c = 4;
	cout << endl;
	cout << "Matrix A \n" << A;
	cout << "Matrix B \n" << B;
	cout << "Matrix C \n" << C;
	cout << "Matrix D \n" << D;
	cout << endl;
	cout << "Vector a \n" << a;
	cout << "Vector b \n" << b;
	cout << "Vector c \n" << c;

	/// Обчислити вираз : F = A+B*_a-B*_c+C/_b; 
	///                   A = F*a + D*b     
	F = A + B * _a - B * _c + C / _b;
	cout << "Matrix F \n" << F;
	A = F * a + D * b;
	cout << "Matrix A \n" << A;
}

