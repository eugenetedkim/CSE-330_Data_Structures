/****************************************************
 * Programmer: Eugene Kim
 * Filename: MySwapMain.cpp
 * Description: to try out swapping as in Weiss p. 30
 * **************************************************/

#include <iostream>
#include <string>
#include "MySwap.h"
using namespace std;

int main()
{
    string str1 = "apples";
    string str2 = "oranges";
    cout << str1 << " and " << str2 << endl;

    swap1(str1,str2);
    cout << str1 << " and " << str2 << endl << endl;

    swap2(str1,str2);
    cout << str1 << " and " << str2 << endl << endl;

    swap3(str1,str2);
    cout << str1 << " and " << str2 << endl << endl;

    return 0;
}
