/*****************************************************************
Eugene Kim
CSE 330
5/24/18
Homework 3
*****************************************************************/

#include <iostream>
#include "BinarySearchTreeLab7.h"

using namespace std;

int main()
{
	BinarySearchTree<int> mybst;
    int next;
    for (int i = 1; i <= 10; i++)
    {
        cout << "Integer: ";
        cin >> next;
        cout << endl;
        mybst.insert(next);
	} 
    cout << endl << "Values entered" << endl;
    mybst.printTree();
    cout << endl;
    mybst.printInternal();
    cout << endl << endl;
    cout << "And with iterators ..." << endl;
    BinarySearchTree<int>::iterator itr; 
    for (itr = mybst.begin(); itr != mybst.end(); ++itr)
    {    
	    cout << *itr << endl;
    }
	cout << endl << endl;
    cout << "Now doing some removals ..." << endl;
    for (int i = 1; i <= 3; i++)
    {
        cout << "Remove? ";
        cin >> next;
        cout << endl;
        mybst.remove(next);
	} 
    cout << endl;
    mybst.printTree();
    cout << endl;
    mybst.printInternal();
    cout << endl << endl;
    cout << "And with iterators ..." << endl;
    itr = mybst.begin();
	for (; itr != mybst.end(); ++itr)
    {
	    cout << *itr << endl;
      	cout << endl << endl;
	}
	return 0;
} 

