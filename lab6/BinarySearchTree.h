/******************************************************************************
Filename: BinarySearchTree.h

Programmer: Eugene Kim
Course: CSE 330
Instructor: Professor Voigt
Date: 5/10/18
Description:    Laboratory -- Week 6
                
                In this lab, you will be implementing the ADT called
                BinarySearchTree. This data structure will provide us with an
                alternative to vectors and linked lists when it comes to
                storing a list of data values.

                Exercise 1: Implement the BinarySearchTree ADT in a file
                BinarySearchTree.h exactly as shown below. As always, make an
                effort to copy mindfully, trying to understand the purpose of
                each line of code as you go along.
******************************************************************************/

// BinarySearchTree.h
// afater Mark A. Weiss, Chapter 4

// KV replaced exceptions with assert statements;
// we are writing <typename C> to indicate that the template type must be
// "comparable", i.e., have define <, > and == operators;

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <cassert>
#include <algorithm>

using namespace std;

template <typename C>
class BinarySearchTree
{
private:
    struct BinaryNode
    {
        C element;
        BinaryNode *left;
        BinaryNode *right;

        BinaryNode(const C & theElement, BinaryNode *lt, BinaryNode *rt)
            : element{theElement}, left{lt}, right{rt} {}

        BinaryNode(C && theElement, BinaryNode *lt, BinaryNode *rt)
            : element{std::move(theElement)}, left{lt}, right{rt} {}
    };

    BinaryNode *root;

    // Internal method to insert into a subtree.
    // x is the item to insert.
    // t is the node that roots the subtree.
    // Set the new root of the subtree.

    void insert(const C & x, BinaryNode* & t)
    {
        if (t == nullptr)
        {
            t = new BinaryNode{x, nullptr, nullptr};
        }
        else if (t->element > x)
        {
            insert(x, t->left);
        }
        else if (t->element < x)
        {
            insert(x, t->right);
        }
        else
        {
            ;   // Duplicate; do nothing
        }
    }

    // Internal method to insert a subtree.
    // x is the item to insert.
    // t is the node that roots the subtree..
    // Set the new root of the subtree.
    
    void insert(C && x, BinaryNode* & t)
    {
        if (t == nullptr)
        {
            t = new BinaryNode{std::move(x), nullptr, nullptr};
        }
        else if (t->element > x)
        {
            insert(std::move(x), t->left);
        }
        else if (t->element < x)
        {
            insert(std::move(x), t->right);
        }
        else
        {
            ;   // Duplicate; do nothing
        }
    }

    // Internal method to remove from a subtree.
    // x is the item to remove.
    // t is the node that roots the subtree.
    // Set the new root of the subtree.

    void remove(const C & x, BinaryNode* & t)
    {
        if (t == nullptr)
        {
            return; // Item not found; do nothing
        }
        else if (t->element > x)
        {
            remove(x, t->left);
        }
        else if (t->element < x)
        {
            remove(x, t->right);
        }
        else if (t->left != nullptr && t->right != nullptr) // Two children
        {
            t->element = findMin(t->right)->element;
            remove(t->element, t->right);
        }
        else
        {
            BinaryNode* oldNode = t;
            t = (t->left != nullptr) ? t->left : t->right;
            delete oldNode;
        }
    }

    // Internal method to find the smallest item in a subtree t.
    // Return node containing the smallest item.
    
    BinaryNode* findMin(BinaryNode* t) const
    {
        if (t == nullptr)
        {
            return nullptr;
        }
        else if (t->left == nullptr)
        {
            return t;
        }
        else
        {
            return findMin(t->left);
        }
    }

    // Internal method to find the largest item in a subtree t.
    // Return node containing the largest item.

    BinaryNode * findMax(BinaryNode* t) const
    {
        if (t != nullptr)
        {
            while (t->right != nullptr)
            {
                t = t->right;
            }
        }
        else
        {
            return t;
        }
    }

    // Internal method to test if an item is in a subtree.
    // x is item to search for.
    // t is the node that roots the subtree.

    bool contains(const C & x, BinaryNode* t) const
    {
        if (t == nullptr)
        {
            return false;
        }
        else if (t->element > x)
        {
            return contains(x, t->left);
        }
        else if (t->element < x)
        {
            return contains(x, t->right);
        }
        else
        {
            return true;    // Match
        }
    }

    void makeEmpty(BinaryNode* & t)
    {
        if (t != nullptr)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        else
        {
            t = nullptr;
        }
    }

    void printTree(BinaryNode* t, ostream & out) const
    {
        if (t != nullptr)
        {
            printTree(t->left, out);
            out << t->element << endl;
            printTree(t->right, out);
        }
    }

    BinaryNode* clone(BinaryNode* t) const
    {
        if (t == nullptr)
        {
            return nullptr;
        }
        else
        {
            return new BinaryNode{t->element, clone(t->left), clone(t->right)};
        }
    }

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

public:
    BinarySearchTree()
        : root{nullptr}
    {
    }

    BinarySearchTree(const BinarySearchTree & rhs)
        : root{nullptr}
    {
        root = clone(rhs.root);
    }

    BinarySearchTree(BinarySearchTree && rhs)
        : root{rhs.root}
    {
        rhs.root = nullptr;
    }

    ~BinarySearchTree()
    {
        makeEmpty();
    }

    BinarySearchTree & operator=(const BinarySearchTree & rhs)
    {
        BinarySearchTree copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    BinarySearchTree & operator=(BinarySearchTree && rhs)
    {
        std::swap(root, rhs.root);
        return *this;
    }

    const C & findMin() const
    {
        assert(!isEmpty());
        return findMax(root)->element;
    }

    const C & findMax() const
    {
        assert(!isEmpty());
        return findMax(root)->element;
    }

    bool contains(const C & x) const
    {
        return contains(x, root);
    }

    bool isEmpty() const
    {
        return root == nullptr;
    }

    void printTree(ostream & out = cout) const
    {
        if (isEmpty())
        {
            out << "Empty tree" << endl;
        }
        else
        {
            printTree(root, out);
        }
    }

    void makeEmpty()
    {
        makeEmpty(root);
    }

    void insert(const C & x)
    {
        insert(x, root);
    }

    void insert(C && x)
    {
        insert(std::move(x), root);
    }

    void remove(const C & x)
    {
        remove(x, root);
    }

    void printInternal()
    {
        printInternal(root, 0);
    }
};
#endif
