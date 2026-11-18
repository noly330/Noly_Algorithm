#include <bits/stdc++.h>
using namespace std;

//TODO:超过内存限制了，以后改,第一次做的时候也是错的
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mpt;
        unordered_map<char,int> mps;
        for(const auto &c : t){
            mpt[c]++;
        }
        string ans;
        int len = INT_MAX;
        int l = 0,r = 0;
        mps[s[l]]++;
        while(r <s.size()){
            if(check(mpt,mps)){
                if(r-l+1 < len){
                    ans = s.substr(l,r-l+1);
                    len = r-l+1;
                }
                mps[s[l]] -- ;
                l++;
                
            }
            else{
                r++;
                if(r<s.size()){
                    mps[s[r]]++;
                }
            }
        }

        return ans;

    }

    bool check(unordered_map<char,int>& mpt,unordered_map<char,int>& mps){
        for(const auto &p : mpt){
            if(mps[p.first] < p.second)
                return false;
        }

        return true;
    }
};