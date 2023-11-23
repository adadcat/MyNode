#include <sstream>
#include <iostream>
#include <vector>
#include "Algorithms.h"
using namespace std;

int main()
{
    Algorithms tmp;

    vector<int> test = { 1,1,2 };
    tmp.removeDuplicates(test);

    return 0;
}