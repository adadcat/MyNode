#include <sstream>
#include <iostream>
#include <vector>
#include "Algorithms.h"
using namespace std;

bool test(string s)
{
    int i = 0;
    int j = s.size() - 1;
    bool cut = true;

    for (int i = 0;i < j;i++)
    {
        char chi = s[i];
        char chj = s[j];
        bool tmp = (s[i] != s[j]);

        if ((s[i] != s[j]) && cut)
        {
            cut = false;
        }
        else if (!cut && s[i] != s[j])
        {
            return false;
        }
        else
        {
            j--;
        }
    }

    return true;
}

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

    //string str = "ccc";
    //tmp.longestPalindrome(str);

    //
    //vector<string> vecfindWords = { "Hello","Alaska","Dad","Peace" };
    //tmp.findWords(vecfindWords);

   // vector<int> intRanks = { 5,4,3,2,1 };
    //tmp.findRelativeRanks(intRanks);

    //string str = "Google";
    //tmp.detectCapitalUse(str);

    //vector<int> nums = { 6,2,6,5,1,2 };
    //tmp.arrayPairSum(nums);

    //vector<int> nums = { 1,1,2,3 };
    //tmp.distributeCandies(nums);

    //vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    //tmp.findLHS(nums);

    //vector<int> nums = { 1,0,0,0,1,0,0 };
    //tmp.canPlaceFlowers(nums,2);

    //vector<int> nums = { -100,-98,-1,2,3,4 };
    //tmp.maximumProduct(nums);

    //vector<int> nums = { 0,1,1,3,3 };
    //tmp.findMaxAverage(nums, 4);

    //vector<int> nums = { 1,1};
    //tmp.findErrorNums(nums);

    //string str = "UD";
    //tmp.judgeCircle(str);

    //vector<int> nums = { 2,2,2,2,2 };
    //tmp.findLengthOfLCIS(nums);

    //string str = "tebbem";
    //tmp.validPalindrome(str);

    //string str1 = "babcba";
    //test(str1);

    //vector<string> str = { "1" };
    //tmp.calPoints(str);

    //string str = "00110011";
    //tmp.countBinarySubstrings(str);

    vector<int> str = { 1,2,2,3,1 };
    tmp.findShortestSubArray(str);

    return 0;
}