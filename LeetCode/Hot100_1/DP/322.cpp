#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+10;
int dp[N];  // dp[i] 表示金额 i 的最少硬币数，0=未计算，-1=无解

class Solution {
public:
    int dfs(vector<int>& coins, int rem) {
        if(rem == 0) return 0;
        if(rem < 0) return -1;
        
        if(dp[rem] != 0) return dp[rem];  // 0 表示未计算
        
        int Min = INT_MAX;
        for(int coin : coins) {
            int res = dfs(coins, rem - coin);
            if(res >= 0 && res < Min) {
                Min = res + 1;  // 先更新 Min
            }
        }
        
        dp[rem] = (Min == INT_MAX) ? -1 : Min;  // 最后存入 dp
        return dp[rem];
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, 0, sizeof(dp));  // 0 表示未计算
        return dfs(coins, amount);
    }
};