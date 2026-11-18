#include<bits/stdc++.h>
using namespace std;


//思路：只能向下走和向右走，那么肯定是左边的路径数量加上上方的路径数量
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m+2][n+2];
        memset(dp,0,sizeof(dp));

        dp[1][1] = 1;

        if(n>1)
            dp[1][2] = 1;

        if(m > 1)
            dp[2][1] = 1;

        for(int i = 1;i<=m;i++){
            for(int j =1;j<=n;j++){
                if(i-1<1 && j-1>=1){
                    dp[i][j] = dp[i][j-1];
                }
                else if(i-1>=1 && j-1<1){
                    dp[i][j] = dp[i-1][j];
                }
                else if(i-1>=1&&j-1>=1){

                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[m][n];
    }
};