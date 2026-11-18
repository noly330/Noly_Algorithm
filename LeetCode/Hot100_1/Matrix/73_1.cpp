#include <bits/stdc++.h>
using namespace std;

//自己的方法，时间复杂度和空间复杂度跟区没什么区别了

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<pair<int, int>> p;

        int row = matrix.size();
        int col = matrix[0].size();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == 0)
                {
                    p.push_back({i, j});
                }
            }
        }
        
        for(int i =0;i<p.size();i++){
            int row1 = p[i].first;
            int col1 = p[i].second;
            for(int j = 0;j<col;j++){
                matrix[row1][j] = 0;
            }

            for(int k =0;k<row;k++){
                matrix[k][col1] =0;
            }
        }
    }
};