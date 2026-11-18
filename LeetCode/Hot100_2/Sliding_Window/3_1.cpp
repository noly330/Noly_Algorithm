#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool> mp;

        int n = s.size();
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        int l = 0;
        int ans = 1;
        mp[s[0]] = true;

        for(int i = 1;i<n;i++){

            //当发现这个字符在滑动列表里存在时
            if(mp.count(s[i]) && mp[s[i]] == true){

                cout<<"发现重复"<<i<<endl;
                while(true){
                    if(s[l] == s[i]){
                        cout<<"这个元素是重复的"<<l<<endl;
                        l++;
                        break;
                    }

                    mp[s[l]] = false;
                    l++;
                }
            }
            mp[s[i]] = true;
            ans = max(ans,i-l+1);

        }

        return ans;
    }
};