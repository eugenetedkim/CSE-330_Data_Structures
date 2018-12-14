// KV, June 2018
// implemention of TreeSort and HeapSort;

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

    /*for (int i = data.size(); i > 1; i--)
    {
        MakeHeap(data.data(), i);
        swap(data.front(), data[i - 1]);
    }*/

    comps = CLUMSY_COUNT;
}
/*
template <typename C>
void MakeHeap(C* arr, int last)
{
    for (int i = 0; i < last; ++i)
    {
        int c = i*2 + 1;
        if (c < last and arr[c] > arr[i])
        {
            swap(arr[c], arr[i]);
            CLUMSY_COUNT++;
        }
        ++c;
        if (c < last and arr[c] > arr[i])
        {
            swap(arr[c], arr[i]);
            CLUMSY_COUNT++;
        }
    }
}
*/      
#endif
