// BinaryHeapMain.cpp
// May 2018

#include <iostream>
#include "BinaryHeap.h"
using namespace std;

int main()
{
    
    BinaryHeap<int> mypq;
    int howmany;
    int next;

    cout << "How many items to store? ";
    cin >> howmany;
    cout << endl;

    for (int i = 1; i <= howmany; i++)
    {
        cout << "Item: ";
        cin >> next;
        cout << endl;
        mypq.insert(next);
        cout << endl;
        mypq.printHeap();
        cout << endl;
    }
    cout << endl;

    mypq.printHeap(); // originally commented out
    cout << endl << endl;

    cout << "Breaking down the PQ top-down ..." << endl;

    while (!mypq.isEmpty())
    {
        mypq.deleteMin(next);
        cout << "removed: " << next << endl;
        mypq.printHeap(); // originally commented out
        cout << endl << endl; // originally commented out
    }

    cout << endl;
    
    return 0;

}
