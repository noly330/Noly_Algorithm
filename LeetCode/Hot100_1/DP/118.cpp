#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i =1;i<numRows;i++){
            vector<int> mid(i+1);  //第一层实际上是i=0，所以要＋1
            for(int j = 0;j<i+1;j++){
                if(j-1>=0){
                    mid[j] += ans[i-1][j-1];
                }
                if(j<i){
                    mid[j] += ans[i-1][j];
                }
            }
            ans.push_back(mid);
        }

        return ans;
    }
};