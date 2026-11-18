#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dp[18][18];
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        memset(dp,0,sizeof(dp));
        int n = s.size();
        // for(int i = 0;i<n;i++){
        //     dp[i][i] = 1;
        // }

        for(int i = n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i == j){
                    dp[i][j] = 1;
                    continue;
                }

                if(s[i] == s[j] ){
                    if(j == i+1 || dp[i+1][j-1] == 1)
                        dp[i][j] = 1;
                }
            }
        }
        vector<string> mid;
        dfs(s,mid,0);

        return ans;
    }

    void dfs(string &s,vector<string> & mid,int i){
        if(i>=s.size()){
            ans.push_back(mid);

            return;
        }

        for(int j=i;j<s.size();j++){
            if(dp[i][j] == 1){
                mid.push_back(s.substr(i,j-i+1));

                dfs(s,mid,j+1);

                mid.pop_back();
            }
        }
    }

};