#include <vector>
#include <iostream>
#include <string>
using namespace std;


vector<int> partitionLabels(string s) {
    // 统计每个字母的下标
    // hash[i] - 每个字母最后出现的位置
    int hash[27] = {0};
    for (int i = 0; i < s.size(); i++) // 遍历s，i 是 s 中的下标
    {
        hash[s[i] - 'a'] = i; // 存的内容是 s 中的下标
    }
    //  直接用ASCII码, 
    //  hash[s[0] - 'a'] = hash['a' - 'a'] = hash[0] 最后更新为 8，即a最远下标是8 
    //  hash[0] = 8 --- a  
    //  hash[1] = 5 --- b
    //  hash[2] = 7 --- c
    //  hash[3] = 14 -- d
    //  ...
    
    //          a, b, c, d,  e,  f,  g,  h,  i,  j,  k,  l,  m, n, o, ...
    //  hash = {8, 5, 7, 14, 15, 11, 13, 19, 22, 23, 20, 21, 0, 0, 0, ...}


    vector<int> result;

    int left = 0;
    int right = 0;
    for (int i = 0; i < s.size(); i++) // 遍历的还是 s
    {
        right = max(right, hash[s[i] - 'a']); // 始终是i之前字母最远边界中的最大值

        if (i == right) // i 正好走到了 i 之前所有字母中的最远下标
        {
            result.push_back(right - left + 1); // 收集该距离
            left = i + 1; // 更新left，开始下一组
        }
    }
 

    return result;
}



int main()
{
    string s = "ababcbacadefegdehijhklij";
    vector<int> result = partitionLabels(s);

    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}