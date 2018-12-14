#include <iostream>

using namespace std;

int main()
{
    int arr[] {1,2,3,4,5,6,7};

    for (auto & x : arr)
    {
        ++x;
    }

    for (auto x : arr)
    {
        cout << x << endl;
    }

    return 0;
}
