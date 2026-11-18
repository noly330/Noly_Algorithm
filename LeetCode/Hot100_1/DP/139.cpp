#include <bits/stdc++.h>
using namespace std;



//思路：
//一维dp,表示s中前i个字符是否能被拼接
//再把这个i分割，比如在j的位置把i个字符分成两部分，因为是从0开始检查的
//所以0-j-1这一部分，肯定被判断过是否是满足条件的，如果满足的话，再看j到i之间的字符满不满足
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> isWord;

        for(auto x : wordDict){
            isWord.insert(x);
        }

        bool dp[310];

        dp[0] = true;

        for(int i =1;i<=s.size();i++){
            for(int j = 0;j<i;j++){
                if(dp[j] && isWord.find(s.substr(j,i-j)) != isWord.end()){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};