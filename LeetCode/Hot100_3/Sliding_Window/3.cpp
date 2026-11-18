#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int l = 0;
        int n = s.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(mp.count(s[i])){
                int last = mp[s[i]];
                l = max(l,last+1);
            }
            
            mp[s[i]] = i;
            ans = max(ans,i-l+1);
            
        }

        return ans;
    }
};