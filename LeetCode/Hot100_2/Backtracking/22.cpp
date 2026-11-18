#include <bits/stdc++.h>
using namespace std;



class Solution {
public:

    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        string mid = "";
        dfs(n,0,0,0,mid);

        return ans;
    }

    void dfs(int n,int p,int l, int r,string& mid){
        if(p >= 2*n){
            ans.push_back(mid);
            return;
        }

        //选择加入左括号
        if(l<n){
            mid.push_back('(');
            dfs(n,p+1,l+1,r,mid);
            mid.pop_back();

        }
        if(r<n && r<l){
            mid.push_back(')');
            dfs(n,p+1,l,r+1,mid);
            mid.pop_back();
        }
    }
};