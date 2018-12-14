#include <iostream>

using namespace std;

int rand_seed()
{
    int seed = static_cast<int>(time(0));
    srand(seed);
    return;
}

int main()
{
    cout << rand_seed() << endl;
}
