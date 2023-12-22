#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <stack>

#include "Algorithms.h"

//供ThreeAndOnePlus()使用
int arr[1000];

void Algorithms::ThreeNAddOne()
{
    int n, count = 0;
    cin >> n;
    while (n != 1) 
    {
        if (n % 2 != 0)
        {
            n = 3 * n + 1;
        }
        n = n / 2;
        count++;
    }
    cout << count;
}

void Algorithms::WhiteThisNumber(int setNumber)
{
    int total = 0;

    vector<string> vec = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };

    if (setNumber < 10)
    {
        cout << vec[setNumber];
        return;
    }

    while (setNumber < 10)
    {
        total += setNumber % 10;

        setNumber = setNumber / 10;
    }

    string strTotal = std::to_string(total);

    for (size_t i = 0;i < strTotal.size();++i)
    {
        int final = strTotal[i] - '0';
        cout << vec[final] << " ";
    }

    /*
    string s;
    cin >> s;
    int sum = 0;
    string str[10] =  {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    for (int i = 0; i < s.length(); i++)
        sum += (s[i] - '0');
    string num = to_string(sum);
    for (int i = 0; i < num.length(); i++) 
    {
        if (i != 0) cout << " ";
        cout << str[num[i] - '0'];
    }

    */
}

void Algorithms::RankingOfResults()
{
    int max = -1, min = 101, score = 0;
    string name;

    string maxname, minname, maxnum, minnum, num;
    int n = 0;
    cin >> n;

    for (int i = 0;i < n;++i)
    {
        cin >> name >> num >> score;

        if (max < score)
        {
            maxname = name;
            maxnum = num;
            max = score;
        }

        if (min > score)
        {
            minname = name;
            minnum = num;
            min = score;
        }
    }

    cout << maxname << " " << maxnum << " " << max << endl;
    cout << minname << " " << minnum << " " << min << endl;
}

void Algorithms::ThreeAndOnePlus()
{
    int inputNum = 0;
    cin >> inputNum;

    //记录待验证的数
    vector<int> numList(inputNum);
    for (int i = 0;i < inputNum;++i) 
    {
        int keyNum = 0;
        cin >> keyNum;
        numList[i] = keyNum;

        //用arr来标记
        while (keyNum != 1)
        {
            if (0 != keyNum % 2)
            {
                keyNum = keyNum * 3 + 1;
            }

            keyNum /= 2;

            if (arr[keyNum] != 1)
            {
                arr[keyNum] = 1;
            }
        }
    }

    //将输入的待验证的正整数排列顺序,从大到小
    int tmp = 0;
    for (int i = 0;i < inputNum - 1;++i)
    {
        for (int j = i;j < inputNum - 1;++j)
        {
            if (numList[j] < numList[j + 1])
            {
                tmp = numList[j];
                numList[j] = numList[j + 1];
                numList[j + 1] = tmp;
            }
        }
    }

    //输出
    for (int i = 0;i < numList.size();++i)
    {
        if (arr[numList[i]] == 0)
        {
            cout << numList[i] << " ";
        }
    }
}

void Algorithms::OutputIntegersByDifferentFormat()
{

}

vector<int> Algorithms::twoSum(vector<int>& nums, int target)
{
    int arr_int[10000];
    for (int i = 0;i < nums.size();i++)
    {
        arr_int[i] = 0;
    }

    for (int i = 0;i < nums.size()-1;i++)
    {
        for (int j = i+1;j < nums.size();j++)
        {
            if (arr_int[i] == 1)
            {
                break;
            }

            int sum = nums[i] + nums[j];
            if (sum == target)
            {
                arr_int[i] = 1;
                arr_int[j] = 1;
            }
        }
    }

    vector<int> tmp;
    for (int i = 0;i < nums.size();++i)
    {
        if (arr_int[i] == 1)
        {
            tmp.push_back(i);
        }
    }

    return tmp;
}

vector<int> Algorithms::High_TwoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> hashtable;

    for (int i = 0; i < nums.size(); ++i) 
    {
        //用相减来遍历vector
        auto it = hashtable.find(target - nums[i]);

        if (it != hashtable.end()) 
        {
            //找到了：
            //返回迭代器的下标，此处循环的下标
            return { it->second, i };
        }

        //如果没找到匹配对，就把访问过的元素和下标加入到map中
        hashtable[nums[i]] = i;
    }
    return {};
    
}

bool Algorithms::isPalindrome(int x)
{
    string str_x = to_string(x);

    string str_backX = str_x;
    reverse(str_backX.begin(), str_backX.end());
   
    if (!str_backX.compare(str_x))
    {
        return true;
    }

    return false;
}

int Algorithms::romanToInt(string s)
{
    unordered_map<char, int> symbolValues = 
    {
       {'I', 1},
       {'V', 5},
       {'X', 10},
       {'L', 50},
       {'C', 100},
       {'D', 500},
       {'M', 1000},
    };

    int sum = 0;
    for (int i = 0;i < s.size();++i)
    {
        int value = symbolValues[s[i]];

        if (i < s.size() - 1 && value < symbolValues[s[i + 1]])
        {
            sum -= value;
        }
        else
        {
            sum += value;
        }
    }


    return sum;
}

string Algorithms::longestCommonPrefix(vector<string>& strs)
{
    string str = "";
    
    if (1 == strs.size())
    {
        return strs[0];
    }

    bool ifReturn = false;
    for (int i = 0;i < strs[0].size();++i)
    {
        char c = strs[0][i];

        for (int j = 1;j < strs.size();++j)
        {
            //从每一个str，分别拿对应序号的字符进行比较
            //有一个不一致，就退出
            if (strs[j][i] != c)
            {
                ifReturn = true;
                break;
            }

            //成功遍历完，将该序列的字符，放到字符串中
            if (j == strs.size() - 1)
            {
                str.push_back(c);
            }
        }
        
        if (ifReturn)
        {
            break;
        }
    }

    return str;
}

bool Algorithms::isValid(string s)
{
    if (s.size() % 2 == 1)
    {
        return  false;
    }

    unordered_map<char, char> symbolValues =
    {
        {'{','}'},
        {'[',']'},
        {'(',')'},
    };

    vector<char> vec;
    for (auto c : s)
    {
        auto iter = symbolValues.find(c);
        if (iter != symbolValues.end())
        {
            vec.push_back(c);
            continue;
        }

        if (!vec.empty())
        {
            auto it = symbolValues.find(*(vec.end() - 1));

            if (it->second == c)
            {
                vec.pop_back();
                continue;
            }
            else
            {
                return false;
            }
        }

        return false;
    }

    if (vec.empty())
    {
        return true;
    }

    return false;
}

int Algorithms::removeDuplicates(vector<int>& nums)
{
    vector<int> vec;
    for (auto num : nums)
    {
        if (vec.empty())
        {
            vec.push_back(num);
        }
        else
        {
            if (*(vec.end() - 1) != num)
            {
                vec.push_back(num);
            }
        }
    }

    nums.clear();

    for (auto i : vec)
    {
        nums.push_back(i);
    }

    return vec.size();
}

int Algorithms::removeElement(vector<int>& nums, int val)
{
    int size = nums.size();
    for (int i = 0;i < size;++i)
    {
        if (nums[i] != val)
        {
            nums.push_back(nums[i]);
        }
    }

    std::reverse(nums.begin(), nums.end());

    while (size)
    {
        nums.pop_back();
        size--;
    }

    return nums.size();
}

int Algorithms::strStr(string haystack, string needle)
{
    int n = haystack.size(), m = needle.size();
    for (int i = 0; i + m <= n; i++) 
    {
        bool flag = true;
        for (int j = 0; j < m; j++) 
        {
            if (haystack[i + j] != needle[j]) 
            {
                flag = false;
                break;
            }
        }
        if (flag) 
        {
            return i;
        }
    }
    return -1;
}

int Algorithms::High_strStr(string haystack, string needle)
{
    int n = haystack.size(), m = needle.size();
    if (m == 0) 
    {
        return 0;
    }

    vector<int> pi(m);
    for (int i = 1, j = 0; i < m; i++) 
    {
        while (j > 0 && needle[i] != needle[j]) 
        {
            j = pi[j - 1];
        }
        if (needle[i] == needle[j]) 
        {
            j++;
        }
        pi[i] = j;
    }

    for (int i = 0, j = 0; i < n; i++) 
    {
        while (j > 0 && haystack[i] != needle[j]) 
        {
            j = pi[j - 1];
        }

        if (haystack[i] == needle[j]) 
        {
            j++;
        }

        if (j == m) 
        {
            return i - m + 1;
        }
    }
    return -1;
    return 0;
}

int Algorithms::searchInsert(vector<int>& nums, int target)
{
    bool ifBelow = false;

    for (int i = 0;i < nums.size();++i)
    {
        if (nums[i] > target)
        {
            ifBelow = true;
        }

        if (ifBelow)
        {
            return i;
        }

        if (nums[i] == target)
        {
            return i;
        }
    }


    return nums.size();
}

int Algorithms::lengthOfLastWord(string s)
{
    string str = "";
    string lastWord = "";
    for (int i = 0;i < s.size();++i)
    {
        if (' ' == s[i])
        {
            str.clear();
            continue;
        }
        else
        {
            str += s[i];
        }

        lastWord = str;
    }

    return lastWord.size();
}

vector<int> Algorithms::plusOne(vector<int>& digits)
{
    int i = digits.size() - 1;

    size_t num = 0;
    size_t multiplication = 1;

    for (i;i >= 0;--i)
    {
        num += (digits[i] * multiplication);

        multiplication *= 10;
    }

    num += 1;
    digits.clear();

    while (num >= 1)
    {
        digits.push_back(num % 10);
        num /= 10;
    }

    reverse(digits.begin(), digits.end());

    return digits;
}

vector<int> Algorithms::High_plusOne(vector<int>& digits)
{
    int n = digits.size();

    for (int i = n - 1; i >= 0; --i) 
    {
        if (digits[i] != 9) 
        {
            ++digits[i];
            for (int j = i + 1; j < n; ++j) 
            {
                //1239999，此时-》1240000
                digits[j] = 0;
            }
            return digits;
        }
    }

    // digits 中所有的元素均为 9
    vector<int> ans(n + 1);
    ans[0] = 1;
    return ans;
}

string Algorithms::addBinary(string a, string b)
{
    string arr = "";
    //交换顺序，方便计算
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    size_t n = a.size() > b.size() ? a.size() : b.size();
    int tmp = 0;

    for (size_t i = 0;i < n;++i)
    {
        tmp += i < a.size() ? (a.at(i) == '1') : 0;
        tmp += i < b.size() ? (b.at(i) == '1') : 0;
        arr.push_back((tmp % 2) ? '1' : '0');
        tmp /= 2;
    }

    if (tmp)
    {
        arr.push_back('1');
    }
    reverse(arr.begin(), arr.end());

    return arr;
}

int Algorithms::mySqrt(int x)
{
    if (x == 1)
    {
        return 1;
    }

    for (size_t i = 0;i < x;++i)
    {
        if (i * i <= x && (i + 1) * (i + 1) > x)
        {
            return i;
        }
    }
    return 0;
}

void Algorithms::merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    //这里nums1.size() == m+n,nums2.size()==n,nums1只有m个元素
    for (int num : nums2)
    {
        nums1.push_back(num);
    }

    int tmp = 0;
    for (int i = 0;i < m + n - 1;++i)
    {
        for (int j = i + 1;j < m + n;++j)
        {
            if (nums1[i] >= nums1[j])
            {
                tmp = nums1[j];
                nums1[j] = nums1[i];
                nums1[i] = tmp;
            }
        }
    }

    reverse(nums1.begin(), nums1.end());
    for (int i = 0;i < n;++i)
    {
        nums1.pop_back();
    }
    reverse(nums1.begin(), nums1.end());
}

vector<int> Algorithms::inorderTraversal(TreeNode* root)
{
    if (root)
    {
        inorderTraversal(root->left);
        rootValue.push_back(root->val);
        inorderTraversal(root->right);
    }

    return rootValue;
}

bool Algorithms::isSameTree(TreeNode* p, TreeNode* q)
{
    if (!p && !q) 
    {
        return true;
    }
    else if (!p || !q) 
    {
        return false;
    }
    else if (p->val != q->val) 
    {
        return false;
    }
    else 
    {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
}

//用于isSymmetric
bool check_isSymmetric(TreeNode* p, TreeNode* q)
{
    if (!left && !right)
    {
        return true;
    }
    if (!left || !right)
    {
        return false;
    }
    return p->val == q->val && check_isSymmetric(p->left, q->right) && check_isSymmetric(p->right, q->right);
}

bool Algorithms::isSymmetric(TreeNode* root)
{
    return check_isSymmetric(root,root);
}

int Algorithms::maxDepth(TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

vector<vector<int>> Algorithms::generate(int numRows)
{
    vector<vector<int>> allParameter;
    vector<int> tmp;

    if (numRows >= 1)
    {
        tmp = {1};
        allParameter.push_back(tmp);
    }

    if (numRows >= 2)
    {
        tmp = {1,1};
        allParameter.push_back(tmp);
    }

    if (numRows < 3)
    {
        return allParameter;
    }
    else
    {
        for (int i = 1;i <= numRows-2;++i)
        {
            tmp.clear();
            tmp.push_back(1);

            int size = allParameter[i].size();

            for (int j = 0;j < size - 1;++j)
            {
                tmp.push_back(allParameter[i][j] + allParameter[i][j + 1]);
            }

            tmp.push_back(1);
            allParameter.push_back(tmp);
        }
    }

    return allParameter;
}

vector<int> Algorithms::getRow(int rowIndex)
{
    vector<vector<int>> allParameter;
    vector<int> tmp;
    rowIndex++;
    if (rowIndex >= 1)
    {
        tmp = { 1 };
        allParameter.push_back(tmp);
    }

    if (rowIndex >= 2)
    {
        tmp = { 1,1 };
        allParameter.push_back(tmp);
    }

    if (rowIndex < 3)
    {
        return allParameter[rowIndex-1];
    }
    else
    {
        for (int i = 1;i <= rowIndex - 2;++i)
        {
            tmp.clear();
            tmp.push_back(1);

            int size = allParameter[i].size();

            for (int j = 0;j < size - 1;++j)
            {
                tmp.push_back(allParameter[i][j] + allParameter[i][j + 1]);
            }

            tmp.push_back(1);
            allParameter.push_back(tmp);
        }
    }

    return allParameter[rowIndex-1];
}

int Algorithms::maxProfit(vector<int>& prices)
{
    int min = prices[0], max = 0;
    int price = 0;
    int minLoc = 0;

    for (int i = 0;i < prices.size();++i)
    {
        if (prices[i] <= min)
        {
            min = prices[i];
            minLoc = i;
        }
        else
        {
            price = (prices[i] - min) > price ? (prices[i] - min) : price;
        }
    }

    return price;
}

bool Algorithms::isPalindrome(string s)
{
    string another_s;
    for (char ch : s)
    {
        if (isalnum(ch))
        {
            another_s += tolower(ch);
        }
    }

    string resive_another(another_s.rbegin(), another_s.rend());

    return another_s == resive_another;
}

bool Algorithms::another_isPalindrome(string s)
{
    string another_s;
    for (char ch : s)
    {
        if (isalnum(ch))
        {
            another_s += tolower(ch);
        }
    }

    size_t size = another_s.size();

    int i = 0;
    int j = size-1;

    while (i < j)
    {
        if (another_s[i] == another_s[j])
        {
            ++i;
            --j;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int Algorithms::singleNumber(vector<int>& nums)
{
    unordered_map<int, int> store;

    for (int num : nums)
    {
        store[num]++;
    }

    for (auto it : store)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }

    return 0;
}

bool Algorithms::hasCycle(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (slow != fast)
    {
        if (fast == nullptr || fast->next == nullptr)
        {
            return false;
        }

        slow = slow->next;
        fast = fast->next->next;
    }

    return true;
}

bool Algorithms::hash_hasCycle(ListNode* head)
{
    unordered_set<ListNode*> hash_store;

    while (head != nullptr)
    {
        if (hash_store.count(head))
        {
            return false;
        }

        hash_store.insert(head);
        head = head->next;
    }

    return true;
}

vector<int> Algorithms::preorderTraversal(TreeNode* root)
{

    return vector<int>();
}

ListNode* Algorithms::getIntersectionNode(ListNode* headA, ListNode* headB)
{
    unordered_set<ListNode*> store_head;
    ListNode* tmp = headA;

    while (tmp)
    {
        store_head.insert(tmp);
        tmp = tmp->next;
    }

    tmp = headB;
    while (tmp)
    {
        if (store_head.count(tmp))
        {
            return tmp;
        }
        tmp = tmp->next;
    }

    return nullptr;
}

string Algorithms::convertToTitle(int columnNumber)
{

    return string();
}

int Algorithms::majorityElement(vector<int>& nums)
{
    int n = nums.size()/2;
    unordered_map <int, int> map_store;

    for (int num : nums)
    {
        map_store[num]++;
    }

    for (auto it : map_store)
    {
        if (it.second > n)
        {
            return it.first;
        }
    }

    return 0;
}

bool Algorithms::isBadVersion(int version)
{
    return false;
}

int Algorithms::firstBadVersion(int n)
{
    int left = 1, right = n;
    while (left < right)
    {
        //不用left+right的目的是防止溢出
        int mid = left + (right - left) / 2;

        if (isBadVersion(mid))
        {
            //mid在[left,mid];
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return left;
}

void Algorithms::moveZeroes(vector<int>& nums)
{
    int n = nums.size();
    int left = 0, right =0;

    while (right < n)
    {
        if (nums[right])
        {
            swap(nums[left], nums[right]);
            left++;
        }

        right++;
    }
}

bool Algorithms::wordPattern(string pattern, string s)
{
    vector<string> vec = Splict(s, " ");

    int length = pattern.size();

    if (length != vec.size())
    {
        return false;
    }

    for (int i = 0;i < length-1;++i)
    {
        for (int j = i+1;j < length;++j)
        {
            if ((pattern[i] == pattern[j] && vec[i] != vec[j]) || (pattern[i] != pattern[j] && vec[i] == vec[j]))
            {
                return false;
            }
        }
    }

    return true;
}

bool Algorithms::canWinNim(int n)
{
    if (n % 4 == 0)
    {
        return false;
    }

    return true;
}

bool Algorithms::isPowerOfThree(int n)
{
    if (n < 0)
    {
        return false;
    }

    if (n == 1)
    {
        return true;
    }

    int i = 0;
    size_t num = 1;
    for (int i = 0;;i++)
    {
        num *= 3;

        if (num < n)
        {
            continue;
        }
        else if (num == n)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

vector<int> Algorithms::countBits(int n)
{
    //偶数是另一个数乘2得到，在二进制中，乘以2相当于直接在后面添0
    // dp[i] = dp[i/2];
    //奇数由比他小一的偶数+1得到
    //dp[i]=dp[i-1]+1   => dp[i]=dp[i/2]+1;

    int i = 1;
    vector<int> vec(n + 1);

    for (int i = 0;i <= n;++i)
    {
        if (i % 2 == 0)
        {
            vec[i] = vec[i / 2];
        }
        else
        {
            vec[i] = vec[i / 2] + 1;
        }
    }

    return vec;
}

bool Algorithms::isPowerOfFour(int n)
{
    if (n < 4 && n != 1)
    {
        return false;
    }
    else if (n == 1)
    {
        return true;
    }


    int i = 0;
    size_t num = 1;

    for (int i = 0;;++i)
    {
        num *= 4;

        if (num < n)
        {
            continue;
        }
        else if (num == n)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

void Algorithms::reverseString(vector<char>& s)
{
    int n = s.size();
    int left = 0, right = n - 1;
    while (left < right)
    {
        swap(s[left], s[right]);

        ++left;
        --right;
    }
}

vector<int> Algorithms::intersection(vector<int>& nums1, vector<int>& nums2)
{
    unordered_set<int> store_set;

    for (int num1 : nums1)
    {
        store_set.insert(num1);
    }

    unordered_set<int> single_num;
    vector<int> vec_num;
    for (int num2 : nums2)
    {
        if (store_set.count(num2))
        {
            single_num.insert(num2);
        }
    }
    
    for (int num : single_num)
    {
        vec_num.push_back(num);
    }

    return vec_num;
}

vector<int> Algorithms::intersect(vector<int>& nums1, vector<int>& nums2)
{
    unordered_map<int, int> store_map;
    for (int num1 : nums1)
    {
        store_map[num1]++;
    }

    vector<int> vec_nums;
    for (int num2 : nums2)
    {
        if (store_map.count(num2))
        {
            vec_nums.push_back(num2);
            --store_map[num2];
            if (store_map[num2] == 0)
            {
                store_map.erase(num2);
            }
        }
    }

    return vec_nums;
}

bool Algorithms::isPerfectSquare(int num)
{
    for(int i=1;;++i)
    {
        double n = double(num) / i;
        if (i < n)
        {
            continue;
        }
        else if (i == n)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

bool Algorithms::canConstruct(string ransomNote, string magazine)
{
    int note_size = ransomNote.size();
    int mag_size = magazine.size();
    if (note_size > mag_size)
    {
        return false;
    }

    unordered_map<char, int> store_mag;

    for (char mag : magazine)
    {
        ++store_mag[mag];
    }

    for (char ran : ransomNote)
    {
        if (store_mag.count(ran))
        {
            --store_mag[ran];

            if (store_mag[ran] < 0)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}

int Algorithms::firstUniqChar(string s)
{
    unordered_map<char, int> store_s;

    for (char ch : s)
    {
        ++store_s[ch];
    }

    int first = s.size();
    for (auto it : store_s)
    {
        if (it.second == 1)
        {
            first = s.find(it.first) < first ? s.find(it.first) : first;
        }
    }

    if (first == s.size())
    {
        return -1;
    }

    return first;
}

char Algorithms::findTheDifference(string s, string t)
{
    unordered_map<char, int> map_s;

    for (char ch : s)
    {
        ++map_s[ch];
    }

    for (char ch : t)
    {
        if (map_s.count(ch))
        {
            --map_s[ch];

            if (map_s[ch] < 0)
            {
                return ch;
            }
        }
        else
        {
            return ch;
        }
    }
}

bool Algorithms::isSubsequence(string s, string t)
{
    int i = 0, j = 0;

    //一个从序列s逐步遍历
    //一个从序列t逐步遍历
    while (i < s.size() && j < t.size())
    {
        //
        if (s[i] == t[j])
        {
            i++;
        }
        j++;
    }

    return i == s.size();
}


bool ifRootNode(TreeNode* root)
{
    //获取左节点
    return !root->left && !root->right;
}

int dfs(TreeNode* node)
{
    int ans = 0;
    if (node->left)
    {
        ans += ifRootNode(node->left) ? node->left->val : dfs(node->left);
    }
    if (node->right && !ifRootNode(node->right))
    {
        ans += dfs(node->right);
    }

    return ans;
}

int Algorithms::sumOfLeftLeaves(TreeNode* root)
{
    if (!root)
    {
        return 0;
    }

    return dfs(root);
}

int Algorithms::longestPalindrome(string s)
{
    unordered_map<char, int> store_s;

    for (char ch : s)
    {
        ++store_s[ch];
    }

    bool ifHasOdd = false;
    int oddNumber = 0;
    int sum = 0;

    for (auto iter : store_s)
    {
        if (iter.second % 2 != 0)
        {
            sum += iter.second - 1;
            ifHasOdd = true;
        }
        else
        {
            sum += iter.second;
        }
    }

    if (ifHasOdd)
    {
        return sum + 1;
    }

    return sum;
}

vector<string> Algorithms::fizzBuzz(int n)
{
    vector<string> vec;

    for (int i = 1;i <= n;++i)
    {
        if (i % 3 == 0 && i %5 !=0)
        {
            vec.push_back("Fizz");
        }
        else if(i%5 ==0 && i % 3!=0)
        {
            vec.push_back("Buzz");
        }
        else if(i % 3 == 0 && i % 5 == 0)
        {
            vec.push_back("FizzBuzz");
        }
        else
        {
            vec.push_back(to_string(i));
        }
    }

    return vec;
}

int Algorithms::thirdMax(vector<int>& nums)
{
    unordered_set<int> set_nums;
    vector<int> vec_nums;

    for (int num : nums)
    {
        set_nums.insert(num);
    }

    for (auto it = set_nums.begin(); it != set_nums.end(); ++it)
    {
        vec_nums.push_back(*it);
    }

    for (int i = 0;i < vec_nums.size();++i)
    {
        for (int j = i;j < vec_nums.size();++j)
        {
            if (vec_nums[i] < vec_nums[j])
            {
                int tmp = vec_nums[i];
                vec_nums[i] = vec_nums[j];
                vec_nums[j] = tmp;
            }
        }
    }

    if (vec_nums.size() < 3)
    {
        return vec_nums[0];
    }

    return vec_nums[2];
}

string Algorithms::addStrings(string num1, string num2)
{
    int add = 0;
    string str = "";

    int i = num1.size() - 1;
    int j = num2.size() - 1;

    while (i >= 0 || j >= 0 || add != 0)
    {
        int x = i >= 0 ? num1[i] - '0' : 0;
        int y = j >= 0 ? num2[j] - '0' : 0;
        int sum = x + y + add;
        str.push_back('0' + sum % 10);
        add = sum / 10;
        --i, --j;
    }

    reverse(str.begin(), str.end());

    return str;
}

int Algorithms::countSegments(string s)
{
    vector<string> vec= Splict(s, " ");

    return vec.size();
}

int Algorithms::arrangeCoins(int n)
{
    int num = n;
    for (int i = 0;i <= n;++i)
    {
        if (num - i < 0)
        {
            return i-1;
        }
        else if(num - i == 0)
        {
            return i;
        }
        num -= i;
    }
    return 0;
}

vector<int> Algorithms::findDisappearedNumbers(vector<int>& nums)
{
    vector<int> vec;
    unordered_set<int> hash_set;
    for (int num : nums)
    {
        hash_set.insert(num);
    }

    for (int i = 1;i <= nums.size();++i)
    {
        if (!hash_set.count(i))
        {
            vec.push_back(i);
        }
    }

    return vec;
}

int Algorithms::findContentChildren(vector<int>& g, vector<int>& s)
{
    //排序
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    //双指针
    int gr = g.size() - 1;
    int sr = s.size() - 1;

    //分饼干
    int n = 0;
    while (gr >= 0 && sr >= 0)
    {
        if (s[sr] >= g[gr])
        {
            sr--;
            gr--;
            n++;
        }
        else
        {
            gr--;
        }
    }
    return n;
}

bool Algorithms::repeatedSubstringPattern(string s)
{
    //abcabc.abcabc
    //abc.abc
    //这两个进行对s的搜索，结果是不一样；上一个在末尾前就搜索到
    return (s+s).find(s, 1) != s.size();
}

int Algorithms::islandPerimeter(vector<vector<int>>& grid)
{
    constexpr static int dx[4] = { 0, 1, 0, -1 };
    constexpr static int dy[4] = { 1, 0, -1, 0 };
    
    int n = grid.size(), m = grid[0].size();
    int ans = 0;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            if (grid[i][j]) 
            {
                int cnt = 0;
                for (int k = 0; k < 4; ++k) 
                {
                    int tx = i + dx[k];
                    int ty = j + dy[k];
                    if (tx < 0 || tx >= n || ty < 0 || ty >= m || !grid[tx][ty])
                    {
                        cnt += 1;
                    }
                }
                ans += cnt;
            }
        }
    }
    return ans;
}

string Algorithms::licenseKeyFormatting(string s, int k)
{
    string str;
    for (char ch : s)
    {
        char  c = toupper(ch);

        if (c == '-')
        {
            continue;
        }

        str += c;
    }

    reverse(str.begin(), str.end());

    int size = str.size();
    int index = 0;
    string finnalStr;

    while (size >= k)
    {
        finnalStr += str.substr(index, k);
        finnalStr.append("-");
        index += k;
        size -= k;
    }

    finnalStr.pop_back();
    if (size <= k && size != 0)
    {
        finnalStr.append("-");
        finnalStr += str.substr(index, size);
    }

    reverse(finnalStr.begin(), finnalStr.end());

    return finnalStr;
}

int Algorithms::findMaxConsecutiveOnes(vector<int>& nums)
{
    int max = 0, i = 0;
    for (int num : nums)
    {
        if (num)
        {
            i++;
        }
        else
        {
            if (i > max)
            {
                max = i;
            }
            i = 0;
        }
    }

    if (i > max)
    {
        return i;
    }

    return max;
}

vector<int> Algorithms::constructRectangle(int area)
{
    vector<int> vec;
    int w, l;
    int ww = 1, ll = 1;

    for (int i = 1;i < area;++i)
    {
        if (area % i != 0)
        {
            continue;
        }

        w = i;
        l = area / i;

        if ((w - l) > 0)
        {
            break;
        }

        ww = w;
        ll = l;
    }

    vec.push_back(ww);
    vec.push_back(ll);

    return vec;
}

int Algorithms::findPoisonedDuration(vector<int>& timeSeries, int duration)
{
    unordered_set<int> hash_set;

    for (int i = 0;i < timeSeries.size();++i)
    {
        for (int j = 0;j < duration;++j)
        {
            hash_set.insert(timeSeries[i] + j);
        }
    }

    return hash_set.size();
}

int Algorithms::high_findPoisonedDuration(vector<int>& timeSeries, int duration)
{
    int sum = 0;

    for (int i = 1;i < timeSeries.size();++i)
    {
        sum += min(timeSeries[i] - timeSeries[i - 1], duration);
    }

    return sum+duration;
}

vector<int> Algorithms::nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
    int m = nums1.size();
    int n = nums2.size();

    vector<int> res(m);
    for (int i = 0; i < m; ++i) 
    {
        int j = 0;

        while (j < n && nums2[j] != nums1[i]) 
        {
            ++j;
        }

        int k = j + 1;

        while (k < n && nums2[k] < nums2[j]) 
        {
            ++k;
        }

        res[i] = k < n ? nums2[k] : -1;
    }
    return res;
}

vector<int> Algorithms::another_nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
    unordered_map<int, int> hashmap;
    stack<int> st;
    for (int i = nums2.size() - 1; i >= 0; --i) 
    {
        int num = nums2[i];
        while (!st.empty() && num >= st.top()) 
        {
            st.pop();
        }

        hashmap[num] = st.empty() ? -1 : st.top();
        st.push(num);
    }

    vector<int> res(nums1.size());
    for (int i = 0; i < nums1.size(); ++i) 
    {
        res[i] = hashmap[nums1[i]];
    }

    return res;
}

vector<string> Algorithms::findWords(vector<string>& words)
{
    unordered_set<char> keywords1 = { 'q','w','e','r','t','y','u','i','o','p','Q','W','E','R','T','Y','U','I','O','P'};
    unordered_set<char> keywords2 = { 'a','s','d','f','g','h','j','k','l','A','S','D','F','G','H','J','K','L'};
    unordered_set<char> keywords3 = { 'z','x','c','v','b','n','m','Z','X','C','V','B','N','M'};
    vector<string> vec;

    for (string word : words)
    {
        bool isSame = true;

        if (keywords1.count(word[0]))
        {
            for (char ch : word)
            {
                if (!keywords1.count(ch))
                {
                    isSame = false;
                    break;
                }
            }
        }
        else if (keywords2.count(word[0]))
        {
            for (char ch : word)
            {
                if (!keywords2.count(ch))
                {
                    isSame = false;
                    break;
                }
            }
        }
        else
        {
            for (char ch : word)
            {
                if (!keywords3.count(ch))
                {
                    isSame = false;
                    break;
                }
            }
        }

        if (isSame)
        {
            vec.push_back(word);
        }
    }

    return vec;
}

string Algorithms::convertToBase7(int num)
{
    return convertToBaseN(num, 7);
}

vector<string> Algorithms::findRelativeRanks(vector<int>& score)
{
    unordered_map<int, int> hash_map;
    vector<int> vec = score;
    sort(vec.begin(), vec.end(), greater<int>());

    for (int i = 0;i < score.size();++i)
    {
        hash_map[score[i]] = i;
    }

    vector<string> str(score.size());
    for (int j = 0;j < vec.size();j++)
    {
        int tmp =hash_map[vec[j]];

        switch (j)
        {
        case 0:
            str[tmp] = "Gold Medal";
            break;
        case 1:
            str[tmp] = "Silver Medal";
            break;
        case 2:
            str[tmp] = "Bronze Medal";
            break;
        default:
            str[tmp] = to_string(j+1);
            break;
        }
    }

    return str;
}

bool Algorithms::checkPerfectNumber(int num)
{
    if (num == 1)
    {
        return true;
    }

    unordered_set<int> hash;

    for (int i = 1;i < num / 2;++i)
    {
        if (num % i == 0)
        {
            hash.insert(i);
            hash.insert(num / i);
        }
    }

    int sum = 0;
    for (int i : hash)
    {
        sum += i;
    }

    return (sum==num*2)?true:false;
}


int sum(int n)
{
    if (0 == n)
    {
        return 0;
    }
    if (1 == n)
    {
        return 1;
    }

    return sum(n - 1) + sum(n - 2);
}

int Algorithms::fib(int n)
{
    int num = sum(n);
    
    return num;
}

bool Algorithms::detectCapitalUse(string word)
{
    bool firstBig = true;
    if ((word[0] - 'a') >= 0)
    {
        firstBig = false;
    }

    for (int i = 1;i < word.size();++i)
    {
        bool secondBig = true;
        if (word[1] - 'a' >= 0)
        {
            secondBig = false;
        }

        if (firstBig)
        {
            if (secondBig)
            {
                if ((word[i] - 'a') >= 0)
                {
                    return false;
                }
            }
            else
            {
                if ((word[i] - 'a') < 0)
                {
                    return false;
                }
            }
        }
        else
        {
            if ((word[i] - 'a') < 0)
            {
                return false;
            }
        }
    }
    
    return true;
}

int Algorithms::findLUSlength(string a, string b)
{
    return a != b ? max(a.length(), b.length()) : -1;
}

string Algorithms::reverseStr(string s, int k)
{
    int length = s.size();

    for (int i = 0;i < s.size();i += 2 * k)
    {
        reverse(s.begin() + i, s.begin() + min(i + k, length));
    }

    return s;
}


vector<string> Algorithms::Splict(const string& source, const string& spliter)
{
    //存放string
    vector<string> store_str;

    //字符的位置
    int head = 0;

    //分割符号位置
    int index = source.find(spliter, head);

    while (index >= 0)
    {
        string str = source.substr(head, index - head);

        store_str.push_back(str);

        head = index + spliter.size();

        index = source.find(spliter,head);

        if (str == "")
        {
            store_str.pop_back();
        }
    }

    int length = source.size();
    if (head < length)
    {
        string lastStr = source.substr(head, length - head);
        store_str.push_back(lastStr);

        //如果传入"-------"，会导致vector全为空
        if (lastStr == "")
        {
            store_str.pop_back();
        }
    }

    return store_str;
}

string Algorithms::convertToBaseN(int num, int N)
{
    //存储字符
    const string words = "0123456789abcdef";

    //num为0
    if (num == 0)
    {
        return "0";
    }

    //标识符
    string flag = "";
    //
    string str = "";

    //num为负数
    if (num < 0)
    {
        flag = "-";
        num = -num;
    }

    int index;
    while (num)
    {
        index = num % N;
        num /= N;
        str += words[index];
    }

    reverse(str.begin(), str.end());

    return flag + str;
}


