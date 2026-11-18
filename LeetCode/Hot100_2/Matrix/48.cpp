#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> a = matrix;
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0;j<matrix[0].size();j++){
                a[j][m-i-1] = matrix[i][j];
            }
        }

        matrix = a;
    }
};