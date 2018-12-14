#include <iostream>

using namespace std;

void print_diag_1toN(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            cout << "_ ";
        }
        cout << i << " ";
        for (int j = 1; j <= n - i; j++)
        {
            cout << "_ ";
        }
        cout << endl;
    }
    return;
}

int main()
{
    unsigned int n;
    cin >> n;
    cout << endl;
    print_diag_1toN(n);
    cout << endl;
}
