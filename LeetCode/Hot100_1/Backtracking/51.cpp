#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<int> a(n,0);
        vector<int> xie1(2*n-1,0);
        vector<int> xie2(2*n-1,0);
        vector<string> x;
        dfs(a,xie1,xie2,x,0,n);

        return ans;
    }

    void dfs(vector<int> &col,vector<int> &xie1,vector<int> &xie2 ,vector<string> &x  ,int p,int n){
        if(p>=n){
            ans.push_back(x);
            return;
        }

        for(int i =0;i<n;i++){  //遍历每一列

            int d1 = p - i + n -1;
            int d2 = p+i;
            if(col[i] == 0 && (xie1[d1] == 0 && xie2[d2] == 0)){
                col[i] = 1;
                xie1[d1] = 1;
                xie2[d2] = 1;
                string row(n,'.');
                row[i] = 'Q';
                x.push_back(row);

                dfs(col,xie1,xie2,x,p+1,n);

                col[i] = 0;
                xie1[d1] = 0;
                xie2[d2] = 0;
                x.pop_back();
            }
        }
    }

};