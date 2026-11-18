#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26];
        int n = s.size();
        for(int i = 0;i<n;i++){
            last[s[i] - 'a'] = i;
        }

        int start = 0;
        int end = last[s[0] - 'a'];
        vector<int> ans;
        for(int i = 0;i<n;i++){
            end = max(end,last[s[i] - 'a']);
            if(i == end){
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }

        return ans;
    }
};