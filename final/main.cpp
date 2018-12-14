#include <iostream>

#include "PriorityQueue.h"

using namespace std;

int main()
{
    PriorityQueue<int> pq;
    pq.push(420);
    pq.push(69);
    pq.push(23);

    for (int i = 0; i < 3; i++)
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}
