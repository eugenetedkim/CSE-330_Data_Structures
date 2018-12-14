#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> container;
    int n;
    cin >> n;
    for (int i = 1; i < n + 1; i++)
    {
        container.push_back(i);
    }
    for (int i = 0; i < container.size(); i++)
    {
        cout << container[i] << endl;
    }

    for (int i = 0; i < container.size(); i++)
    {
        
       // cout << container[i] << " ";
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                cout << container[i] << " ";
            }
            else
            {
                cout << "_ ";
            }
                // cout << "_ ";
        }
        cout << endl;
    }
   
}
