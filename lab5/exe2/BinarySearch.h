/********************************************************************
Programmer: Eugene Kim
Filename: BinarySearch.h
Course: CSE 330
Instructor: Professor Voigt
Date: 5/10/18
********************************************************************/

#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <iostream>

int binary_search(int x, const Vector<int> & vec, int & steps)
{
    int low = 0;
    int high = vec.size() - 1;
    steps = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        steps++;

        if (vec[mid] < x)
        {
            low = mid + 1;
        }
        else if (vec[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int binary_search(int x, const List<int> & lst, int & steps)
{
    int low = 0;
    int high = lst.size() - 1;
    steps = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        steps++;

        if (lst.nth(mid, steps) < x)
        {
            low = mid + 1;
        }
        else if (lst.nth(mid, steps) > x)
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

#endif
