#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

template <typename T>
void swap_xy(T & x, T & y)
{
    T temp;
    temp = x;
    x = y;
    y = temp;
    return;
}

template <typename T>
int minimum(int i, int j, vector<T> vec)
{
    if (i == j)
    {
        return i;
    }

    int mindex = i;

    T min = vec[i];

    for (int k = i; k <= j; k++)
    {
        if (vec[k] < min)
        {
            min = vec[k];
            mindex = k;
        }
    }
    return mindex;
}

template<typename T>
void selection_sort(vector<T> & vec)
{
    int nextmin;
    for (int i = 0; i < vec.size(); i++)
    {
        nextmin = minimum(i, vec.size() - 1, vec);
        swap_xy(vec[i], vec[nextmin]);       
    }
   return; 
}

int main()
{
    vector<int> vec = {5, 3, 7, 9, 2, 1, 8};
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }

    cout << endl;
    
    selection_sort(vec);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
}
