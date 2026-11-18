#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    vector<string> ans;
    string mid ="";
    int n;

    unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        
        dfs(0,digits);

        return ans;

    }

    void dfs(int p ,string &digits){

        if(p == n){
            ans.push_back(mid);
            return;
        }
        
        string x = phoneMap[digits[p]];
        for(int i =0;i<x.size();i++){
            mid.push_back(x[i]);
            dfs(p+1,digits);
            mid.pop_back();
        }


    }
};