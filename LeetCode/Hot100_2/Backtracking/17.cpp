#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> ans;
    unordered_map<char, string> phoneMap{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};
    vector<string> letterCombinations(string digits)
    {
        int n = digits.size();
        string mid = "";
        dfs(0,n,digits,mid);
        return ans;
    }

    void dfs(int p, int n, string digits, string mid)
    {
        if (p == n)
        {
            ans.push_back(mid);
            return;
        }
        string s = phoneMap[digits[p]];
        for(int i = 0;i<s.size();i++){
            mid += s[i];
            dfs(p+1,n,digits,mid);
            mid.pop_back();
        }
    }
};