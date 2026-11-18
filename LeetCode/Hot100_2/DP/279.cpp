#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        
        dp[0] = 0;
        for(int i = 1;i<=n;i++){
            int minmm = INT_MAX;

            for(int j=1;j*j<=i;j++){ //枚举所有平方数
                //加1代表的是，当前平方数也就是j*j
                dp[i] = min(dp[i],dp[i-j*j]+1);
            }
        }

        return dp[n];
    }
};