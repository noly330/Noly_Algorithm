#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        
        int a=0,b=0,ans=1;
        for(int i = 1;i<=n;i++){
            a=b;
            b=ans;
            ans=a+b;
        }

        return ans;
    }
};