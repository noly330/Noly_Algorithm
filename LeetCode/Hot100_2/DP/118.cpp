#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});

        for(int i = 1;i<numRows;i++){
            vector<int> mid;
            for(int j = 0;j<=i;j++){
                if(j == 0){
                    mid.push_back(ans[i-1][0]);
                }
                else if(j == i){
                    mid.push_back(ans[i-1][i-1]);
                }
                else{
                    mid.push_back(ans[i-1][j-1]+ans[i-1][j]);
                }

                
            }

            ans.push_back(mid);
        }

        return ans;
    }
};