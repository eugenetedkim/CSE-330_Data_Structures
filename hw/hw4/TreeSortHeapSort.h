/*****************************************************************
 * Name: Eugene Kim
 * Course: CSE 330
 * Instructor: Professor Voigt
 * Date: 12 June 2018 
 * Filname: TreeSortHeapSort.h
 * Description: Implemenation of TreeSort and HeapSort
 *****************************************************************/

#ifndef TSORTHSORT_H_
#define TSORTHSORT_H_

#include <vector>
    
#include "BST_HW4.h"
#include "BinaryHeap_HW4.h"

using namespace std;

extern int CLUMSY_COUNT;

template <typename C>
void TreeSort(vector<C> & data, int & comps)
{
    CLUMSY_COUNT = 0;

    BinarySearchTree<C> bst;

    for (int i = 0; i < data.size(); i++)
    {
        bst.insert(data[i]);
    }

    int i = 0;

    typename BinarySearchTree<C>::iterator itr = bst.begin();

    for (; itr != bst.end(); itr++)
    {
        data[i] = *itr;
        i++;
    }

    comps = CLUMSY_COUNT;
}

template <typename C>
void HeapSort(vector<C> & data, int & comps)
{
    CLUMSY_COUNT = 0;

    BinaryHeap<C> BH(data);

    for (int i = 0; i < data.size(); ++i)
    {
        data[i] = BH.findMin();
        BH.deleteMin();
    }

    comps = CLUMSY_COUNT;
}

#endif
