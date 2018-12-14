#include <iostream>
#include "Map.h"

using namespace std;

int main()
{
    Map<string, int> basket;
    int howmany;
    cout << "How many fruits in basket? ";
    cin >> howmany;

    string nextf;
    for (int i = 1; i <= howmany; i++)
    {
        cout << "Fruit? ";
        cin >> nextf;
        cout << endl << "How many? ";
        cin >> howmany;
        cout << endl << endl;
        basket[nextf] = howmany;
    }
    cout << "Content of my basket:" << endl;
    basket.printMap();
    cout << endl << endl;

    basket.remove("apple");
    return 0;
}
