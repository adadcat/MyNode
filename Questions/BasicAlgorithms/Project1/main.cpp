#include <sstream>
#include <iostream>
#include <vector>
#include "Algorithms.h"
using namespace std;

int main()
{
    Algorithms tmp;

    vector<string> test = { "cir","car" };
    tmp.longestCommonPrefix(test);

    return 0;
}