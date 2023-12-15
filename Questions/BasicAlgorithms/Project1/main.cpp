#include <sstream>
#include <iostream>
#include <vector>
#include "Algorithms.h"
using namespace std;

int main()
{
    Algorithms tmp;
    //vector<int> vec = { 7, 1, 5, 3, 6, 4 };
    //auto it = tmp.maxProfit(vec);

    //vector<int> vec = { 4,1,2,1,2 };
    //tmp.singleNumber(vec);

    //string str = "abba";
    //string input = "dog cat cat dog";
    //tmp.wordPattern(str,input);

    //tmp.isPowerOfThree(1162261468);

    //vector<int> vec1 = { 1,2,2,1 };
    //vector<int> vec2 = { 2,2 };
    //tmp.intersection(vec1, vec2);

    //tmp.isPerfectSquare(16);

    //string a = "aa";
    //string b = "aab";
    //tmp.canConstruct(a, b);

    //string str = "loveleetcode";
    //tmp.firstUniqChar(str);

    //string a = "abcd";
    //string b = "abcde";
    //tmp.findTheDifference(a, b);

    //string a = "ab";
    //string b = "baab";
    //tmp.isSubsequence(a, b);

    /*
    string str = "À≠”–œ–÷√";
    vector<char> vec;
    for (auto &it : str)
    {
        vec.push_back(it);
    }
    reverse(str.begin(), str.end());
    cout << str;
    */

    //tmp.countSegments("        ");

    //tmp.arrangeCoins(2);

    //vector<int> nums = { 1,2,2,1 };
    //tmp.findDisappearedNumbers(nums);
    
    string str = "ccc";
    tmp.longestPalindrome(str);
    
    return 0;
}