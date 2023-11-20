#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

#include "Algorithms.h"

//��ThreeAndOnePlus()ʹ��
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

    //��¼����֤����
    vector<int> numList(inputNum);
    for (int i = 0;i < inputNum;++i) 
    {
        int keyNum = 0;
        cin >> keyNum;
        numList[i] = keyNum;

        //��arr�����
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

    //������Ĵ���֤������������˳��,�Ӵ�С
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

    //���
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
        //�����������vector
        auto it = hashtable.find(target - nums[i]);

        if (it != hashtable.end()) 
        {
            //�ҵ��ˣ�
            //���ص��������±꣬�˴�ѭ�����±�
            return { it->second, i };
        }

        //���û�ҵ�ƥ��ԣ��Ͱѷ��ʹ���Ԫ�غ��±���뵽map��
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
    return 0;
}

