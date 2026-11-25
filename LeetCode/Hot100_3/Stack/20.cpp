#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> mp{
            {'(',')'},
            {'[',']'},
            {'{','}'}
        };
        stack<char> stk;
        for(int i = 0; i < s.size();i++){
            if(mp.count(s[i])){
                stk.push(s[i]);
            }
            else{
                if(stk.size() == 0){
                    return false;
                }
                if(s[i] == mp[stk.top()]){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
        }

        return stk.size() == 0;
    }
};