#include <iostream>
#include "Lab4Exmaple.h"
#include "Vector.h"
#include "Matrix.h"
#include "MyAssoc.h"



int mainExample1() {

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
	return 2;
}



/// <summary>
	/// Задано : A,B,C,D,F  -  Матриці комплесних чисел
	///          a,b,c  -  Вектори комплесних чисел 
	///          _a,_b,_c - комплексні числа.
	/// Обчислити вираз : F = A+B*_a-B*_c+C/_b; 
	///                   c = F*a + D*b         
	/// </summary>
	/// <returns></returns>

int mainExample2() {
	ComplexMatrix A(5),  B(5), C(5), D(5), F(5);
	ComplexVector a(5), b(5), c(5);
	ComplexDouble _a(3.2, 5), _b(1, 2), _c = RandComplexDouble();
	
		A.RandComplexMatrix();
		B.RandComplexMatrix();
		C.RandComplexMatrix();
		D.RandComplexMatrix();
		a.RandComplexVector();
		b.RandComplexVector();
		c.RandComplexVector();

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
	///                   c = F*a + D*b     
	F = A + B * _a - B * _c + C / _b;
	cout << "Matrix F \n" << F;
	c = F * a + D * b;
	cout << "Vector c \n" << c;

	
	return 3;
}
int mainExample3() {
	cout << " End begin \n";
	uint Flight[5] = { 12,32,23,43,43 };
	MyTime MTime[5] = { {9,10}, {10,30}, {10,30}, {10,30} , {15,35} };
	MyAssoc dbase(5, Flight, MTime);
	dbase.TableFlight();
	MyTime r = { 10,30 }, ro;
	uint fli = 32;
	ro = dbase[fli];
	cout << " Test : MyTime operator[](uint&s  )  " << "Flight " << fli << " time   " <<
		ro << endl;
	cout << " Test : uint	operator[](MyTime&s)  " << " time  " << r << " light  " <<
		dbase[r] << endl;
	cout << " Flight with time :   9   to  11 \n";
	dbase(9, 11);
	cout << " End test \n";
	return 4;
}

