#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> arr = matrix;

        for(int i = 0;i<n;i++){
            for(int j =0;j<n;j++){
                //arr[j][n-i-1] = matrix[i][j];
                //上和下都行
                arr[i][j] = matrix[n-j-1][i];
            }
        }
        matrix = arr;
    }
};