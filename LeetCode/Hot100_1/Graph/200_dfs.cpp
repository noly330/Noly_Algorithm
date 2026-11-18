#include<bits/stdc++.h>
using namespace std;


const int N = 310;
int visited[N][N];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int n,m;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        memset(visited,0,sizeof(visited));
        

        int ans =0;
        n = grid.size();
        m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j] != 0)
                    continue;

                if(grid[i][j] == '1'){
                    ans++;
                    dfs(i,j,grid);
                }
            }
        }

        return ans;
    }


    void dfs(int x,int y,vector<vector<char>> & grid){
        visited[x][y] = 1;
        for(int i = 0;i<4;i++){
            int xx = x + dx[i];
            int yy = y + dy[i];

            if(xx < 0 || xx >= n || yy<0 ||yy>=m)
                continue;

            if(visited[xx][yy] == 1 || grid[xx][yy] == '0')
                continue;
            
            dfs(xx,yy,grid);
        }
    }
};