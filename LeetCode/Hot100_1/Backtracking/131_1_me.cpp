#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> mid;
        dfs(s,0,0,s.size(),mid);

        return ans;
    }

    //a存储分割点
    void dfs(string s,int i,int j,int n,vector<string> &mid){
        if(j >= n){

            if(isHuiWen(s.substr(i,j-i))){
                mid.push_back(s.substr(i,j-i));
                ans.push_back(mid);
                mid.pop_back();
            }

            return;
        }

        //试图分割
        if(isHuiWen(s.substr(i,j-i+1))){
            mid.push_back(s.substr(i,j-i+1));
            dfs(s,j+1,j+1,n,mid);

            //回溯
            mid.pop_back();
        }

        //不分割
        dfs(s,i,j+1,n,mid);
    }

    bool isHuiWen(string s){
        if(s.size() ==0){
            return false;
        }
        if(s.size() == 1){
            return true;
        }

        int l =0;
        int r =s.size()-1;

        while(l<r){
            if(s[l]!= s[r]){
                return false;
            }

            l++,r--;
        }

        return true;
    }
};