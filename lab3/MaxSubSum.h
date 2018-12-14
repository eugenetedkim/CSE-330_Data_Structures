// Filename: MaxSubSum.h

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

void rand_seed();
int rand_int(int a, int b);
void random_vector(int k, int from, int upto, vector<int>& v);
int max_subseq_sum_cube(const vector<int>& vec, int& ops);
int max_subseq_sum_quad(const vector<int>& vec, int& ops);
int max_subseq_sum_lin(const vector<int>& vec, int& ops);

