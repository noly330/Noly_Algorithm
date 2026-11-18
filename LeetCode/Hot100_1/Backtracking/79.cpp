#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n, m;
    bool ans = false;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int visited[10][10];

    bool exist(vector<vector<char>> &board, string word)
    {
        memset(visited,0,sizeof(visited));
        n = board.size();
        m = board[0].size();

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j] == word[0]){

                    visited[i][j] = 1;
                    dfs(board,i,j,word,1);
                    visited[i][j] = 0;
                    if(ans == true){
                        return true;
                    }
                }
            }
        }

        return false;
    }

    void dfs(vector<vector<char>> &board, int x, int y, string &word, int num)
    {
        if (num >= word.size())
        {
            ans = true;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m)
            {
                continue;
            }
            if(visited[xx][yy] == 1){
                continue;
            }

            if(board[xx][yy] == word[num]){
                visited[xx][yy] = 1;
                dfs(board,xx,yy,word,num+1);
                visited[xx][yy] = 0;
            }
        }
    }
};