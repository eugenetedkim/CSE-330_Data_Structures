/****************************************************
 * Programmer: Eugene Kim
 * Filename: MySwap.h
 * Description: to try out swapping as in Weiss p. 30
 * **************************************************/

#include <iostream>

using namespace std;

template <class T>
void swap1(T & x, T & y)
{
    T tmp = x;  // copies of T objects;
    x = y;
    y = tmp;
    return;
}

template <class T>
void swap2(T & x, T & y)            // more efficient
{                                   // with rvalues
    T tmp = static_cast<T &&>(x);
    x = static_cast<T &&>(y);
    y = static_cast<T &&>(tmp);
}

template <class T>
void swap3(T & x, T & y)
{                           // equivalent + easier;
    T tmp = std::move(x);   // implicit use of
    x = std::move(y);       // rvalues with 'move'
    y = std::move(tmp);
    return;
}

