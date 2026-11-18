#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(int i = 0;i<wordDict.size();i++){
            st.insert(wordDict[i]);
        }
        int n = s.size();
        vector<bool> dp(n+1,false);  //表示前n个字符是否可分割
        dp[0] = true; //没有字符，当可以分割的
        for(int i = 0;i<n;i++){
            if (!dp[i]) continue;  //前i个字符，也就是下表0~i-1的string
            for(int j = i;j<n;j++){
                if(st.count(s.substr(i,j-i+1))){
                    dp[j+1] = true;  //表示s里面,[0,j]的符合分割条件
                }
            }
        }

        return dp[n];
    }
};