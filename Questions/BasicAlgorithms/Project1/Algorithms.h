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

//定义一个链表
//后续依据此链表
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Algorithms
{
public:
    //1
    //3n+1猜想
    /*
    对任何一个正整数 n
    如果它是偶数，那么把它砍掉一半；
    如果它是奇数，那么把 (3n+1) 砍掉一半
    这样一直反复砍下去，最后一定在某一步得到 n=1。
    */
    void ThreeNAddOne();

    //2
    //写出这个数
    /*
    读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
    输入格式：
    自然数 n 的值
    输出格式：
    在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。
    */
    void WhiteThisNumber(int setNumber);

    //3
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

    //4
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

    //5
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

    //6
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

    //7
    //回文数
    //
    bool isPalindrome(int x);

    //8
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

    //9
    //最长公共前缀
    /*
    编写一个函数来查找字符串数组中的最长公共前缀。
    如果不存在公共前缀，返回空字符串 ""。
    */
    string longestCommonPrefix(vector<string>& strs);

    //10
    //有效的括号
    /*
    给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
    有效字符串需满足：
    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。
    每个右括号都有一个对应的相同类型的左括号
    */
    bool isValid(string s);

    //11
    /*
    将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
    */
    //ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)

    //12
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

    //13
    //移除元素
    /*
    给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
    不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
    元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。
    */
    int removeElement(vector<int>& nums, int val);

    //14
    //找出字符串中第一个匹配项的下标
    /*
    给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
    如果 needle 不是 haystack 的一部分，则返回  -1 。
    */
    //暴力解题，直接匹配
    int strStr(string haystack, string needle);

    //15
    //找出字符串中第一个匹配项的下标
    //KMP算法解题
    int High_strStr(string haystack, string needle);

    //16
    //搜索插入位置
    /*
    给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
    如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
    请必须使用时间复杂度为 O(log n) 的算法。
    */
    int searchInsert(vector<int>& nums, int target);

    //17
    //最后一个单词的长度
    /*
    给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中 最后一个 单词的长度。
    单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
    */
    int lengthOfLastWord(string s);

    //18
    //加一
    /*
    给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
    最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
    你可以假设除了整数 0 之外，这个整数不会以零开头。
    */
    //这里将数组拆分，但是数组可包含的数远大于数字，会出现越界的情况。
    vector<int> plusOne(vector<int>& digits);

    //19
    //加一
    //直接进行对数组的操作
    vector<int> High_plusOne(vector<int>& digits);

    //20
    //二进制求和
    /*给你两个二进制字符串 a 和 b ，以二进制字符串的形式返回它们的和.*/
    string addBinary(string a, string b);

    //21
    //x的算术平方根
    /*
    给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
    由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
    注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
    */
    int mySqrt(int x);
    
    //22
    //爬楼梯
    /*
    假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
    每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
    */
    int climbStairs(int n);

    //23
    //合并两个有序数组
    /*
    给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
    请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
    注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，
    其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
    */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

    //24
    //二叉树的中序遍历
    /*
    给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
    */
    vector<int> inorderTraversal(TreeNode* root);

    //25
    //相同的树
    /*
    给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
    如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
    */
    bool isSameTree(TreeNode* p, TreeNode* q);

    //26
    //对称二叉树
    /*
    给你一个二叉树的根节点 root ， 检查它是否轴对称。
    */
    bool isSymmetric(TreeNode* root);

    //27
    //二叉树的最大深度
    /*
    给定一个二叉树 root ，返回其最大深度。
    二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。
    */
    int maxDepth(TreeNode* root);

    //28
    //杨辉三角
    /*
    给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。
    在「杨辉三角」中，每个数是它左上方和右上方的数的和。
    */
    vector<vector<int>> generate(int numRows);

    //29
    //杨辉三角2
    /*
    * 给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
    */
    vector<int> getRow(int rowIndex);

    //30
    //卖卖股票的最佳时机
    /*
    给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
    你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
    返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
    */
    int maxProfit(vector<int>& prices);

    //31
    //验证回文串
    /*
    如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。
    字母和数字都属于字母数字字符。
    给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。
    */
    //字符串倒转
    bool isPalindrome(string s);
    //双指针
    bool another_isPalindrome(string s);

    //32
    //只出现一次的数字
    /*
    给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
    你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。
    */
    int singleNumber(vector<int>& nums);

    //33
    //环形链表
    /*
    给你一个链表的头节点 head ，判断链表中是否有环。
    如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。
    为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
    如果链表中存在环 ，则返回 true 。 否则，返回 false 。
    */
    //双指针，快慢指针
    bool hasCycle(ListNode* head);
    //哈希表存储位置
    bool hash_hasCycle(ListNode* head);
    
    //34
    //二叉树的前序遍历
    /*
    给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
    */
    vector<int> preorderTraversal(TreeNode* root);

    //35
    //相交链表
    /*
    给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
    题目数据 保证 整个链式结构中不存在环。
    注意，函数返回结果后，链表必须 保持其原始结构 。
    自定义评测：
    评测系统 的输入如下（你设计的程序 不适用 此输入）：
    intersectVal - 相交的起始节点的值。如果不存在相交节点，这一值为 0
    listA - 第一个链表
    listB - 第二个链表
    skipA - 在 listA 中（从头节点开始）跳到交叉节点的节点数
    skipB - 在 listB 中（从头节点开始）跳到交叉节点的节点数
    */
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB);

    //36
    //Excel表格名称
    /*
    给你一个整数 columnNumber ，返回它在 Excel 表中相对应的列名称。
    例如：
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
    */
    string convertToTitle(int columnNumber);

    //37
    //多数元素
    /*
    给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
    你可以假设数组是非空的，并且给定的数组总是存在多数元素。
    */
    int majorityElement(vector<int>& nums);

    //38
    //第一个错误版本
    /*
    你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。
    由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。
    假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。
    你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version 是否在单元测试中出错。
    实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。
    */
    //二分查找：但是合理的选择二分查找的值
    bool isBadVersion(int version);
    int firstBadVersion(int n);

    //39
    //移动0
    /*
    给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
    请注意 ，必须在不复制数组的情况下原地对数组进行操作。
    */
    //双指针，快慢指针
    void moveZeroes(vector<int>& nums);

    //40
    //单词规律
    /*
    给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。
    这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。
    */
    //这里写了一个公用的字符串拆分的函数
    bool wordPattern(string pattern, string s);

    //41
    //nim游戏
    /*
    桌子上有一堆石头。
    你们轮流进行自己的回合， 你作为先手 。
    每一回合，轮到的人拿掉 1 - 3 块石头。
    拿掉最后一块石头的人就是获胜者。
    假设你们每一步都是最优解。
    请编写一个函数，来判断你是否可以在给定石头数量为 n 的情况下赢得游戏。
    如果可以赢，返回 true；否则，返回 false 。
    */
    bool canWinNim(int n);

    //42
    //3的幂
    /*
    给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true ；否则，返回 false 。
    整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3x
    */
    bool isPowerOfThree(int n);

    //43
    //比特位计数
    /*
    给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 
    返回一个长度为 n + 1 的数组 ans 作为答案。
    */
    //数学，奇偶
    vector<int> countBits(int n);

    //44
    //4的幂
    /*
    给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 true ；否则，返回 false 。
    整数 n 是 4 的幂次方需满足：存在整数 x 使得 n == 4x
    */
    bool isPowerOfFour(int n);

    //45
    //反转字符串
    /*
    编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
    不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
    */
    void reverseString(vector<char>& s);

    //46
    //两个数组的交集
    /*
    给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。
    我们可以 不考虑输出结果的顺序 。
    */
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2);

    //47
    //两个数组的交集 二
    /*
    给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。
    返回结果中每个元素出现的次数，
    应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
    */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2);

    //48
    //有效的完全平方数
    /*
    给你一个正整数 num 。如果 num 是一个完全平方数，则返回 true ，否则返回 false 。
    完全平方数 是一个可以写成某个整数的平方的整数。换句话说，它可以写成某个整数和自身的乘积。
    不能使用任何内置的库函数，如  sqrt 。
    */
    bool isPerfectSquare(int num);

    //49
    //赎金信
    /*
    给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
    如果可以，返回 true ；否则返回 false 。
    magazine 中的每个字符只能在 ransomNote 中使用一次。
    */
    bool canConstruct(string ransomNote, string magazine);

    //50
    //字符串中的第一个唯一字符
    /*
    给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 - 1 。
    */
    int firstUniqChar(string s);

    //51
    //找不同
    /*
    给定两个字符串 s 和 t ，它们只包含小写字母。
    字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
    请找出在 t 中被添加的字母。
    */
    char findTheDifference(string s, string t);

    //52
    //判断子序列
    /*
    给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
    字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（
    例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
    */
    //动态规划，双指针，贪心算法
    bool isSubsequence(string s, string t);

    //53
    //左叶子之和
    /*
    给定二叉树的根节点 root ，返回所有左叶子之和。
    */
    int sumOfLeftLeaves(TreeNode* root);

    //54
    //最长回文串
    /*
    给定一个包含大写字母和小写字母的字符串 s ，返回 通过这些字母构造成的 最长的回文串 。
    在构造过程中，请注意 区分大小写 。比如 "Aa" 不能当做一个回文字符串。
    */
    int longestPalindrome(string s);

    //55
    //fuzz buzz
    /*
    给你一个整数 n ，找出从 1 到 n 各个整数的 Fizz Buzz 表示，并用字符串数组 answer（下标从 1 开始）返回结果，其中：
    answer[i] == "FizzBuzz" 如果 i 同时是 3 和 5 的倍数。
    answer[i] == "Fizz" 如果 i 是 3 的倍数。
    answer[i] == "Buzz" 如果 i 是 5 的倍数。
    answer[i] == i （以字符串形式）如果上述条件全不满足。
    */
    vector<string> fizzBuzz(int n);

    //56
    //第三大的数
    /*
    给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。
    */
    int thirdMax(vector<int>& nums);

    //57
    //字符串相加
    /*
    给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
    你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。
    */
    string addStrings(string num1, string num2);

    //58
    //字符串的单词数
    /*
    统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。
    请注意，你可以假定字符串里不包括任何不可打印的字符。
    示例:
    输入: "Hello, my name is John"
    输出: 5
    解释: 这里的单词是指连续的不是空格的字符，所以 "Hello," 算作 1 个单词。
    */
    int countSegments(string s);

    //59
    //排列硬币
    /*
    你总共有 n 枚硬币，并计划将它们按阶梯状排列。对于一个由 k 行组成的阶梯，其第 i 行必须正好有 i 枚硬币。阶梯的最后一行 可能 是不完整的。
    给你一个数字 n ，计算并返回可形成 完整阶梯行 的总行数。
    */
    int arrangeCoins(int n);

    //60
    //找到所有数组中消失的数字
    /*
    给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。
    请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
    示例 1：
    输入：nums = [4,3,2,7,8,2,3,1]
    输出：[5,6]
    示例 2：
    输入：nums = [1,1]
    输出：[2]
    */
    vector<int> findDisappearedNumbers(vector<int>& nums);

    //61
    //分发饼干
    /*
    假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
    对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。
    如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。
    你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。
    */
    //双指针，贪心算法
    //没懂
    int findContentChildren(vector<int>& g, vector<int>& s);

    //62
    //重复的字符串
    /*
    给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
    */
    bool repeatedSubstringPattern(string s);

    //63
    //岛屿的周长
    /*
    给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。
    网格中的格子 水平和垂直 方向相连（对角线方向不相连）。
    整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
    岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。
    格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。
    */
    int islandPerimeter(vector<vector<int>>& grid);

    //64
    //密钥格式化
    /*
    给定一个许可密钥字符串 s，仅由字母、数字字符和破折号组成。字符串由 n 个破折号分成 n + 1 组。你也会得到一个整数 k 。
    我们想要重新格式化字符串 s，使每一组包含 k 个字符，除了第一组，它可以比 k 短，但仍然必须包含至少一个字符。此外，两组之间必须插入破折号，并且应该将所有小写字母转换为大写字母。
    返回 重新格式化的许可密钥 。
    */
    string licenseKeyFormatting(string s, int k);

public:
    //用于：二叉树的中序遍历
    vector<int> rootValue;

    //相同的树
    bool returnValue = true;

    //二叉树的最大深度
    int max_depth = 0;
    vector<int> vec_depth;

 private:
     //定义一个字符串分割函数
     /*
     string str="123,,234,,556,,34";
     统一将,,给删除
     将分割出来的字符串存入一个vector<string>中
     */
     vector<string> Splict(const string& source, const string& soliter);
};

