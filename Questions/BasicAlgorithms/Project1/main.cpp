#include <sstream>
#include <iostream>
#include <vector>
#include "Algorithms.h"
using namespace std;

int main()
{
    int test = 1;
    test = (test > 1 ? 3 : 4, 5);



    Algorithms tmp;

    TreeNode* p = new TreeNode();
    p->val = 1;

    TreeNode* p1 = new TreeNode();
    p1->val = 2;

    p->left = p1;

    TreeNode* q = new TreeNode();
    q->val = 1;

    TreeNode* q2 = new TreeNode();
    q2->val = 2;

    q->right = q2;

    auto it = tmp.isSameTree(p, q);

    return 0;
}