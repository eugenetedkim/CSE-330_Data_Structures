#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include "BinaryHeap_HW4.h"

using namespace std;

template<typename C>
class PriorityQueue
{
private:
    int theSize;
    BinaryHeap<C> theheap;
public:
    PriorityQueue() {}
    PriorityQueue(const PriorityQueue & rhs) : theheap{rhs.theheap}, theSize{rhs.theSize} {}
    const C & top() const;
    void push(const C & x);
    void pop();
};

template<typename C>
const C & PriorityQueue<C>::top() const
{
    theheap.findMin();
}

template<typename C>
void PriorityQueue<C>::push(const C & x)
{
    theheap.insert(x);
}

template<typename C>
void PriorityQueue<C>::pop()
{
    theheap.deleteMin();
}

#endif
