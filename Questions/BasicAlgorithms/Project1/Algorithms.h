#pragma once
#include <iostream>
using namespace std;

//定义一个临时的树
//后续依据此树
struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Algorithms
{
public:
    //3n+1猜想
    /*
    对任何一个正整数 n
    如果它是偶数，那么把它砍掉一半；
    如果它是奇数，那么把 (3n+1) 砍掉一半
    这样一直反复砍下去，最后一定在某一步得到 n=1。
    */
    void ThreeNAddOne();

    //写出这个数
    /*
    读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
    输入格式：
    自然数 n 的值
    输出格式：
    在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。
    */
    void WhiteThisNumber(int setNumber);

    //成绩排名
    /*
    读入 n>0名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。
    输入格式：
    第 1 行：正整数 n
    第 2 行：第 1 个学生的姓名 学号 成绩
    第 3 行：第 2 个学生的姓名 学号 成绩
     ... ... ...
    第 n+1 行：第 n 个学生的姓名 学号 成绩
    其中姓名和学号均为不超过 10 个字符的字符串，成绩为 0 到 100 之间的一个整数.
    这里保证在一组测试用例中没有两个学生的成绩是相同的。

    输出格式：
    对每个测试用例输出 2 行，第 1 行是成绩最高学生的姓名和学号，第 2 行是成绩最低学生的姓名和学号，字符串间有 1 空格。
    */
    void RankingOfResults();

    //(3n+1)猜想升级版
    /*
    卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。
    例如对 n=3 进行验证的时候，我们需要计算 3、5、8、4、2、1，则当我们对 n=5、8、4、2 进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这 4 个数已经在验证3的时候遇到过了，我们称 5、8、4、2 是被 3“覆盖”的数。我们称一个数列中的某个数 n 为“关键数”，如果 n 不能被数列中的其他数字所覆盖。
    现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。
    输入格式：
    每个测试输入包含 1 个测试用例，第 1 行给出一个正整数 K (<100)，第 2 行给出 K 个互不相同的待验证的正整数 n (1<n≤100)的值，数字间用空格隔开。
    输出格式：
    每个测试用例的输出占一行，按从大到小的顺序输出关键数字。数字间用 1 个空格隔开，但一行中最后一个数字后没有空格。
    */
    void ThreeAndOnePlus();

    //换个格式输出整数
    /*
    让我们用字母 B 来表示“百”、字母 S 表示“十”，用 12...n 来表示不为零的个位数字 n（<10）
    换个格式来输出任一个不超过 3 位的正整数。例如 234 应该被输出为 BBSSS1234
    因为它有 2 个“百”、3 个“十”、以及个位的 4。
    输入格式：
    每个测试输入包含 1 个测试用例，给出正整数 n（<1000）。
    输出格式：
    每个测试用例的输出占一行，用规定的格式输出 n。
    */
    void OutputIntegersByDifferentFormat();

    //两数之和
    /*
    *给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数
    并返回它们的数组下标。
    你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
    你可以按任意顺序返回答案。
    */
    vector<int> twoSum(vector<int>& nums, int target);
    //两数之和，官方题解
    vector<int> High_TwoSum(vector<int>& nums, int target);

    //回文数
    //
    bool isPalindrome(int x);

    //罗马数字转整数
    /*
    罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
    字符          数值
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    例如， 罗马数字 2 写做 II ，即为两个并列的 1 。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
    通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。
    数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。

    这个特殊的规则只适用于以下六种情况：
    I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
    X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
    C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
    给定一个罗马数字，将其转换成整数。
    */
    int romanToInt(string s);

    //最长公共前缀
    /*
    编写一个函数来查找字符串数组中的最长公共前缀。
    如果不存在公共前缀，返回空字符串 ""。
    */
    string longestCommonPrefix(vector<string>& strs);

    //有效的括号
    /*
    给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
    有效字符串需满足：
    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。
    每个右括号都有一个对应的相同类型的左括号
    */
    bool isValid(string s);

    //
    /*
    将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
    */
    //ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)

    //删除有序数组中的重复项
    /*
    给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
    元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
    考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：
    更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。
    nums 的其余元素与 nums 的大小不重要。
    返回 k 。
    */
    int removeDuplicates(vector<int>& nums);

    //移除元素
    /*
    给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
    不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
    元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
    */
    int removeElement(vector<int>& nums, int val);

    //找出字符串中第一个匹配项的下标
    /*
    给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
    如果 needle 不是 haystack 的一部分，则返回  -1 。
    */
    //暴力解题，直接匹配
    int strStr(string haystack, string needle);

    //找出字符串中第一个匹配项的下标
    //KMP算法解题
    int High_strStr(string haystack, string needle);

    //搜索插入位置
    /*
    给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
    如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
    请必须使用时间复杂度为 O(log n) 的算法。
    */
    int searchInsert(vector<int>& nums, int target);

    //最后一个单词的长度
    /*
    给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。
    单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
    */
    int lengthOfLastWord(string s);

    //加一
    /*
    给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
    最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
    你可以假设除了整数 0 之外，这个整数不会以零开头。
    */
    //这里将数组拆分，但是数组可包含的数远大于数字，会出现越界的情况。
    vector<int> plusOne(vector<int>& digits);

    //加一
    //直接进行对数组的操作
    vector<int> High_plusOne(vector<int>& digits);

    //二进制求和
    /*给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和.*/
    string addBinary(string a, string b);

    //x的算术平方根
    /*
    给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
    由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
    注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
    */
    int mySqrt(int x);
    
    //爬楼梯
    /*
    假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
    每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
    */
    int climbStairs(int n);

    //合并两个有序数组
    /*
    给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
    请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
    注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，
    其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
    */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

    //二叉树的中序遍历
    /*
    给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
    */
    vector<int> inorderTraversal(TreeNode* root);

    //相同的树
    /*
    给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
    如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
    */
    bool isSameTree(TreeNode* p, TreeNode* q);

    //对称二叉树
    /*
    给你一个二叉树的根节点 root ， 检查它是否轴对称。
    */
    bool isSymmetric(TreeNode* root);

    //二叉树的最大深度
    /*
    给定一个二叉树 root ，返回其最大深度。
    二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
    */
    int maxDepth(TreeNode* root);

public:
    //用于：二叉树的中序遍历
    vector<int> rootValue;

    //相同的树
    bool returnValue = true;
};

