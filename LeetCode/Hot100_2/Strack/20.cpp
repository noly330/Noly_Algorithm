#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> mp = {
            {'(',')'},
            {'[',']'},
            {'{','}'}
        };

        stack<char> stk;
        for(int i =0;i<s.size();i++){
            if(mp.count(s[i])){
                stk.push(s[i]);
            }
            else{
                if(stk.empty()||s[i] != mp[stk.top()]){
                    return false;
                }
                else{
                    stk.pop();
                }
            }
        }

        return stk.empty();
    }
};