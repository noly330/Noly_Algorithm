#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        //记录上一次出现的位置
        unordered_map<char,int> mp;
        int n = s.size();
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        int l = 0;
        int ans = 1;

        mp[s[0]] = 0;

        for(int r = 1;r<n;r++){
            if(mp.count(s[r])){
                l = max(mp[s[r]] + 1,l); //避免左指针回退
            }

            mp[s[r]] = r;
            ans = max(ans,r-l+1);
        }

        return ans;
        
    }
};