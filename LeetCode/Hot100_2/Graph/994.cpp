#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    int ans = 0;
    int goodCount = 0;
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 1){
                    goodCount ++;
                }
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        while(q.size()){
            int d = q.size();
            bool isBeBad = false;
            for(int i = 0;i<d;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i = 0;i<4;i++){
                    int xx = x + dx[i];
                    int yy = y + dy[i];

                    if(xx<0||xx>=n||yy<0||yy>=m){
                        continue;
                    }
                    if(grid[xx][yy] == 1){
                        isBeBad = true;
                        goodCount --;
                        grid[xx][yy] = 2;
                        q.push({xx,yy});
                    }
                }
            }
            if(isBeBad)
                ans++;
        }

        if(goodCount>0){
            return -1;
        }

        return ans;
    }


};