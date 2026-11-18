#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n, m;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int visited[12][12];
    queue<pair<int, int>> q;
    int ans = 0;
    int orangesRotting(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        memset(visited, 0, sizeof(visited));

        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
        bfs(grid);

        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }

        return ans;
    }

    void bfs(vector<vector<int>> &grid)
    {
        while (q.size())
        {
            bool isIncrease = false;
            int l = q.size();
            for (int i = 0; i < l; i++)
            {

                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if (grid[x][y] == 2)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        int xx = x + dx[i];
                        int yy = y + dy[i];
                        if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                            continue;
                        if (grid[xx][yy] != 1)
                            continue;
                        if (visited[xx][yy] == 1)
                            continue;

                        isIncrease = true;
                        visited[xx][yy] = 1;
                        grid[xx][yy] = 2;
                        q.push({xx, yy});
                    }
                }
            }
            if(isIncrease)
                ans++;
        }
    }
};