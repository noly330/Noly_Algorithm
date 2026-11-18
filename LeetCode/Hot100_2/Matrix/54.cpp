#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dx[4] = {-1,0,1,0};
        int dy[4] = {0,1,0,-1};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> st(m,vector<int>(n,0));

        int k = 0;
        int dir = 1;
        int x = 0,y = 0;
        vector<int> ans;
        ans.push_back(matrix[0][0]);
        k++;
        st[0][0] = 1;
        while(k < m*n){
            int xx = x + dx[dir];
            int yy = y + dy[dir];
            if( xx<0||xx>=m||yy<0||yy>=n||st[xx][yy] == 1){
                dir = (dir+1)%4;
                continue;
            }
            x = xx;
            y = yy;
            st[xx][yy] = 1;
            ans.push_back(matrix[xx][yy]);
            k++;
        }

        return ans;
    }
};