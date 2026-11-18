#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int n = s.size();
        int ans = 0;
        int start = 0;
        for(int i = 0;i<n;i++){
            if(mp.count(s[i])){
                start = max(mp[s[i]]+1,start);
            }
            mp[s[i]] = i;
            ans = max(ans,i-start+1);
        }
        return ans;
    }
};