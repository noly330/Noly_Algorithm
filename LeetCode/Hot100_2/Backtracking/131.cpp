#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i; j < n; j++)
            {
                if(i == j){
                    dp[i][j] = 1;
                    continue;
                }
                if (s[i] == s[j])
                {
                    if (j == i + 1 || dp[i + 1][j - 1] == 1)
                    {
                        dp[i][j] = 1;
                    }
                }
            }
        }
        vector<string> mid;
        dfs(dp,0,n,s,mid);
        return ans;
    }

    void dfs(vector<vector<int>> &dp, int start,int n,string s, vector<string>& mid)
    {
        if(start >= n){
            ans.push_back(mid);
            return;
        }
        for(int j = start;j<n;j++){
            if(dp[start][j] == 1){
                mid.push_back(s.substr(start,j - start+1));
                dfs(dp,j+1,n,s,mid);
                mid.pop_back();
            }
        }
    }
};