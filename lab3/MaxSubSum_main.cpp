// Filename: MaxSubSum_main.cpp

#include <iostream>
#include <vector>

using namespace std;

#include "MaxSubSum.h"

int main()
{
    int no_ops = 0;
    vector<int> mynums;

    for (int i = 1; i <= 6; i++)
    {
        int how_many;
        cout << "Vector size: ";
        cin >> how_many;
        cout << endl;

        rand_seed();
        random_vector(how_many, 1, 50, mynums);

        int maxsum1 = max_subseq_sum_cube(mynums, no_ops);
        cout << "maxsum1: " << maxsum1 << " " << "no_ops: " << no_ops << endl;

        int maxsum2 = max_subseq_sum_quad(mynums, no_ops);
        cout << "maxsum2: " << maxsum2 << " " << "no_ops: " << no_ops << endl;

        int maxsum3 = max_subseq_sum_lin(mynums, no_ops);
        cout << "maxsum3: " << maxsum3 << " " << "no_ops: " << no_ops << endl;
    }
    return 0;
}
