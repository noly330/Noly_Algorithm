#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> mid;
        vector<int> col(n,0);
        vector<int> diag1(2*n - 1,0);
        vector<int> diag2(2*n - 1,0);
        dfs(0,n,mid,col,diag1,diag2);

        return ans;
    }


    void dfs(int row,int n,vector<string>& mid,vector<int>& col,
    vector<int>& diag1,vector<int>& diag2){
        if(row == n){
            ans.push_back(mid);
            return;
        }
        
        for(int i = 0;i<n;i++){
            int d1 = row - i + n - 1;
            int d2 = row + i;
            if(col[i] == 0 && diag1[d1] == 0 && diag2[d2] == 0){
                col[i] = 1;
                diag1[d1] = 1;
                diag2[d2] = 1;
                string x(n,'.');
                x[i] = 'Q';
                mid.push_back(x);

                dfs(row+1,n,mid,col,diag1,diag2);
                col[i] = 0;
                diag1[d1] = 0;
                diag2[d2] = 0;
                mid.pop_back();
            }
        }
    }
};