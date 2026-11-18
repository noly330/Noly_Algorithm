#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int m;
    int n;
    bool ans = false;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        vector<vector<int>> st(m,vector<int>(n,0));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j] == word[0]){
                    st[i][j] = 1;
                    dfs(board,st,word,i,j,1);
                    st[i][j] = 0;
                }

                if(ans == true){
                    return true;
                }
            }
        }
        return false;
    }

    void dfs(vector<vector<char>>& board,vector<vector<int>>& st,string &word,int x,int y,int num){

        if(num == word.size()){
            ans = true;
            return;
        }

        for(int i = 0;i<4;i++){
            int xx = x +dx[i];
            int yy = y + dy[i];
            if(xx<0||xx>=m||yy<0||yy>=n)
                continue;
            if(st[xx][yy] == 1)
                continue;
            if(board[xx][yy] == word[num]){
                st[xx][yy] = 1;
                dfs(board,st,word,xx,yy,num + 1);
                st[xx][yy] = 0;
            }
        }

    }
};