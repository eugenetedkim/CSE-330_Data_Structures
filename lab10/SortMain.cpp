/* Filename: SortMain.cpp
 *
 * Exercise 2:  Write your own test program in file SortMain.cpp
 *              which generates an unordered vector or 20 random
 *              integers and two copies of this vector.
 *
 *              The program is to sort the first vector copy
 *              with insertionSort, the second vector copy with
 *              selection Sort, and the third copy with
 *              mergeSort.
 *
 *              The test program should print each vector pre-
 *              and post-sorting.
 */

#include <iostream>
#include <vector>

#include "Sort.h"

using namespace std;

void rand_seed()
{
    int seed = static_cast<int>(time(0));
    srand(seed);
    return;
}

int rand_int(int a, int b)
{
    return a+ rand() % (b - a + 1);
}

void rand_int_vector(int k, vector<int> & vec)
{
    if (k <= 0)
    {
        return;
    }

    for (int i = 1; i <= k - 1; i++)
    {
        int rnum = rand_int(1, 99);
        vec.push_back(rnum);
    }
    return;
}

int main()
{

    vector<int> my_vec_1;

    cout << "How many random integers do you want generated in my_vec_1? ";
    int how_many;
    cin >> how_many;

    rand_seed();

    rand_int_vector(how_many, my_vec_1);

    vector<int> my_vec_2(my_vec_1);
    vector<int> my_vec_3(my_vec_1);

    cout << "my_vec_1 before sorting:" << endl;
    for (int i = 0; i < my_vec_1.size(); i++)
    {
        cout << my_vec_1[i] << endl;
    }

    insertionSort(my_vec_1);
    cout << endl << "my_vec_1 after sorting:" << endl;
    for (int i = 0; i < my_vec_1.size(); i++)
    {
        cout << my_vec_1[i] << endl;
    }

    cout << endl << "my_vec_2 before sorting:" << endl;
    for (int i = 0; i < my_vec_2.size(); i++)
    {
        cout << my_vec_2[i] << endl;
    }

    selectionSort(my_vec_2);
    cout << endl << "my_vec_2 after sorting:" << endl;
    for (int i = 0; i < my_vec_2.size(); i++)
    {
        cout << my_vec_2[i] << endl;
    }

    cout << endl << "my_vec_3 before sorting:" << endl;
    for (int i = 0; i < my_vec_3.size(); i++)
    {
        cout << my_vec_3[i] << endl;
    }
    
    mergeSort(my_vec_3);
    cout << endl << "my_vec_3 after sorting:" << endl;
    for (int i = 0; i < my_vec_3.size(); i++)
    {
        cout << my_vec_3[i] << endl;
    }
}
