#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;

BST::BST() // consructor prototype
{
    root = NULL;
}

/*
 * BST:: is in front of the return type because 
 * the node pointer has been defined in the
 * BST class making it unknown to BST.cpp.
 * That's why we have to make the node pointer definition
 * known by adding BST:: in front of the node pointer return type.
 */
BST::node* BST::CreateLeaf(int key)
{
    node* n = new node;
    n->key = key;
    n->left = NULL;
    n->right = NULL;

    return n;
}



