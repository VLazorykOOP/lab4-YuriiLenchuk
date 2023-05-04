 // OOPLab4T.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №4. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//


#include <iostream>
#include "Lab4Exmaple.h"
using namespace std;
// Ваші файли загловки 
//
#include "Lab4Exmaple.h"
int main()
{
    cout << "OOP.  Laboratory work #4.\n";

    char ch = '5';
    do {
        system("cls");
        cout << "1 Task1\n";
        cout << "2 Task2\n";
        cout << "3 Task3\n";

        ch = cin.get();

        cin.get();

        switch (ch) {
        case '1': mainExample1();   break;
        case '2': mainExample1();   break;
        case '3': mainExample1();   break;
        case '4': return 0;
        }
        cout << " Press any key and enter\n";
        ch = cin.get();
    } while (ch != '4');

    return 0;

}