/******************************************************************************
Name: Eugene Kim
File: VectorMain.cpp
Description: Homework 1
Course: CSE 330
Instructor: Voigt
*******************************************************************************/

#include <iostream>
#include "Vector.h"

using namespace std;

void print_vector(Vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return;
}

int main()
{
    Vector <int> v1;
    for (int i = 2; i <= 16; i++)
    {
        v1.push_back(i);
        i++;
    }

    cout << "v1: ";
    print_vector(v1);

    cout << "Enter index number to remove from v1: ";
    int number;
    cin >> number;
    v1.erase(number);
    cout << "After deleting index " << number;
    cout << ", v1: ";
    print_vector(v1);

    cout << "Enter an index number to add an element into that location: ";
    int number2;
    cin >> number2;

    cout << "Enter an the number of the element you want to add to index " << number2 << ": ";
    int number3;
    cin >> number3;

    Vector <int> v2;
    for (int i = 2; i <= 16; i++)
    {
        v2.push_back(i);
        i++;
    }

    v2.insert(number2, number3);
    cout << "v2: ";
    print_vector(v2);

    return 0;

/*
    Vector<int> v2(v1);

    cout << "v2(v1): ";
    print_vector(v2);

    Vector<int> v3 = v2;

    cout << "v3=v2: ";
    print_vector(v3);

    Vector<int> v4(static_cast<Vector<int>&&>(v3));

    cout << "v4(&&v3): ";
    print_vector(v4);
    cout << "v3: ";
    print_vector(v3);

    Vector<int> v5 = static_cast<Vector<int>&&>(v2);

    cout << "v5=&&v2: ";
    print_vector(v5);
    cout << "v2: ";
    print_vector(v2);
*/
}
