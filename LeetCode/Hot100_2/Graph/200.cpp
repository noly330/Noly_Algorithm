#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int visted[310][310];
    int ans = 0;
    int n;
    int m;
    int numIslands(vector<vector<char>> &grid)
    {
        n = grid.size();
        m = grid[0].size();

        memset(visted, 0, sizeof(visted));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (visted[i][j] == 0 && grid[i][j] == '1')
                {
                    bfs(grid, i, j);
                    
                    ans++;
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<char>> &grid, int x, int y)
    {

        visted[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                continue;
            if (visted[xx][yy] == 1)
                continue;
            if (grid[xx][yy] == '0')
                continue;

            dfs(grid, xx, yy);
        }
    }

    void bfs(vector<vector<char>> &grid, int a, int b)
    {
        queue<pair<int, int>> q;
        q.push({a, b});
        visted[a][b] = 1;
        while (q.size())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m)
                    continue;
                if (visted[xx][yy] == 1)
                    continue;
                if (grid[xx][yy] == '0')
                    continue;
                q.push({xx,yy});
                visted[xx][yy] = 1;
            }
        }
    }
};