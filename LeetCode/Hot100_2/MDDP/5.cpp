#include <bits/stdc++.h>
using namespace std;

//TODO:学习中心扩散法和动态规划法
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        if(n < 2){
            return s;
        }
        //自身就是回文串
        for(int i = 0;i<n;i++){
            dp[i][i] = 1;
        }
        int maxlen = 1;
        int begin = 0;

        for(int l = 2;l<=n;l++){
            for(int i = 0;i<n;i++){
                int j = i + l -1;

                if(j>=n){
                    break;
                }

                if(s[i]!=s[j]){
                    dp[i][j] = false;
                }
                else{
                    if(j - i < 3){
                        dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                }

                if(dp[i][j] == true){
                    if(j - i +1 > maxlen){
                        maxlen = j-i+1;
                        begin = i;
                    }
                }
            }
        }
        return s.substr(begin,maxlen);
    }
};