#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 17 电话号码的字母组合

const string letterMap[10] = {
    "", // 0
    "", // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs",// 7
    "tuv", // 8
    "wxyz" // 9
};


string path;
vector<string> result;


void backtracking(const string& digits, int digitsIndex)
{
    // digitsIndex 是digits的下标，这里往下走就是取digits的下一个数，下一个字符组合
    if (digitsIndex == digits.size()) // digits取到最后一个，终止
    {
        result.push_back(path);
        return;
    }
    int digit = digits[digitsIndex] - '0'; // 把index指向的数字（字符型）转为int
    string letters = letterMap[digit]; // 取出对应的字符集
    // 处理单层的字符组合
    for (int i = 0; i < letters.size(); i++)
    {
        path.push_back(letters[i]);
        backtracking(digits, digitsIndex + 1);
        path.pop_back();
    }
}

vector<string> letterCombinations(string digits) 
{
    if (digits.size() == 0)  return result;
    backtracking(digits, 0);
    return result;        
}


int main()
{
    string digits = "23";
    vector<string> result = letterCombinations(digits);
    for (string s : result)
    {
        cout << s << ",";
    }
    cout << endl;


    return 0;
}