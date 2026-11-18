#include<bits/stdc++.h>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<bool>> cc;
        cc = vector<vector<bool>>(row,vector<bool>(col,0));
        vector<int> ans;

        ans.push_back(matrix[0][0]);
        cc[0][0] = true;
        int dir = 0;
        int currentRow = 0;
        int currentCol = 0;
        int k =1;

        while(k < row * col){
            int nextRow = currentRow +dy[dir];
            int nextCol = currentCol +dx[dir];
            if(nextRow >= row || nextCol >=col
            || nextRow <0 || nextCol<0
            || cc[nextRow][nextCol] == 1){
                dir = (dir+1) % 4;
                continue;
            }

            ans.push_back(matrix[nextRow][nextCol]);
            cc[nextRow][nextCol] = true;
            currentRow = nextRow;
            currentCol = nextCol;
            k++;
        }

        return ans;
    }
};