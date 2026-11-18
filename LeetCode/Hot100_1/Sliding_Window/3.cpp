#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int ans = 0;
        unordered_set<char> set;

        int j = 0;
        for(int i=0;i<n;i++){
            
            while(j<n){
                if(set.count(s[j])){
                    break;
                }
                set.insert(s[j]);
                //ans = max(ans,j-i+1);  或者用下面那个
                j++;
            }
            ans = max(ans,j-i+1-1);
            set.erase(s[i]);
        }
        return ans;
        
    }
};