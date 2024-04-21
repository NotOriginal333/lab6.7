#include "Array.h" 
#include <iostream> 
#include <time.h> 
#include <stdexcept> 
#include <exception> 
#include <cmath> 

using namespace std;

typedef Array::value_type* TArray;

int main()
{
    int n;
    cout << "n= "; cin >> n;
    Array c = Array(2 * n);

    srand((unsigned)time(NULL));
    Array::value_type A = -50;
    Array::value_type B = 50;

    TArray a = new Array::value_type[n];

    for (int i = 0; i < 2 * n; i++)
        a[i] = A + rand() % int(B - A + 1);

    Array::iterator l = const_cast<Array::iterator>(c.begin());
    for (int j = 0; j < 2 * n; j++, l++)
        *l = a[j];
    cout << "Original array:\n" << c << endl;

    c.sumAverage();
    cout << "Array after calculating sum and average:\n" << c << endl;

    c.replace();
    cout << "Array after replacing even numbers:\n" << c;

    Array uniqueArray = c;
    uniqueArray.unique_copy();
    cout << "Unique elements in the array:\n" << uniqueArray;

    Array positiveArray = c;
    IsPositive<Array::value_type> isPositive;
    positiveArray.unique_copy_if(isPositive);
    cout << "Unique positive elements in the array:\n" << positiveArray;

    cin.get();
    cin.get();
    return 0;
}
