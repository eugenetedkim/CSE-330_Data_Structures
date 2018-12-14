/*************************************************************
Filename: BinarySearchTreeMain.cpp

Programmer: Eugene Kim
Course: CSE 330 Data Structures
Instructor: Professor Voigt
Date: 5/13/18
Description:
    Exercise 2: Program your own file BinarySearchTreeMain.cpp
                in which your main() function will test the
                new data structure.  Declare an instance of
                BinarySearchTree(short: BST) suitable to hold
                integer values.  Then enter a random sequence
                of 25 integer values into the data structure
                (your values should NOT be in sorted order).

                Use the print_Tree() member function in order
                to print out the values of the BST structure - 
                What do you notice?

                Answer: The output is sorted in ascending 
                        order.

                Next, remove 5 values from your BST and save
                them in a vector (use your own Vector.h or STL
                <vector>).  Print out the reduced BST.

    Exercise 3: Next add the following member function to your
                BinarySearchTree class:

                Under public:

                void printInternal()
                {
                    print_Internal(root, 0);
                }

                Under private:

                void printInternal(BinaryNode* t, int offset)
                {
                    for (int i = 1; i <= offset; i++)
                    {
                        cout << "..";
                    }
                    cout << t->element << endl;
                    printInternal(t->left, offset + 1);
                    printInternal(t->right, offset + 1);
                }

                Go back to your program
                BinarySearchTreeMain.cpp and change printTree
                to print Internal.  Compile and run your
                program, and see what you get. 

                Answer: Segmentation fault (core dumped)

                Next, insert the 5 values that have been 
                removed back into the BST.  Print the new
                BST with printInternal.  How does this printed
                BST compare with the BST that the program
                printed before the removal of the 5 values?
                Same?  Different?  Explanation?

                Different; after implementing printInternal
                and switching printTree for it, I get a
                segmentation fault error.  I am not sure why
                this is happening even though I followed 
                the directions.  I have no problems until I
                used printInternal().
**************************************************************/

#include <iostream>
#include <vector>
#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> BST;
    vector <int> VEC[26] = {23, 7, 11, 2, 19, 16, 9, 15, 25, 24,
        20, 8, 1, 3, 12, 22, 10, 21, 4, 18, 5, 13, 17, 20, 18, 14};
    
    cout << "The Vector VEC contains the following integers:" << endl;
    
    for (int i = 0; i < VEC.size(); i++)
    {
        cout << VEC[i] << endl;
    }

    cout << endl;

    for (int i = 0; i < VEC.size(); i++)
    {
        BST.insert(VEC[i]);
    }

    cout << "The Binary Search Tree BST contains the following integers:" << endl;

    BST.printTree();
    
    /**
    Next, remove 5 values from your BST and save
    them in a vector (use your own Vector.h or STL
    <vector>).  Print out the reduced BST.
    **/

    cout << endl << endl;
/*
    Vector<int> vec;

    for (int i = 0; i < 5; i++)
    {
        cout << "Which value do you want to remove? ";
        int remove_target;
        cin >> remove_target;
        if (BST.contains(remove_target) == false)
        {
            cout << "The value you entered is not valid" << endl;
        }
        else
        {
            vec.push_back(remove_target);
            BST.remove(remove_target);
        }
    }

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }

    cout << endl;

    for (int i = 0; i < vec.size(); i++)
    {
        int n = vec[i];
        BST.insert(n);
    }

    BST.printTree();
*/
}
