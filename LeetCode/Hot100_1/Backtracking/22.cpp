#include <bits/stdc++.h>
using namespace std;


vector<string> ans;
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        ans.clear();
        string res ="";
        dfs(0,0,n,res);

        return ans;
    }

    void dfs(int l, int r, int n, string &res)
    {
        if (l == n && r == n)
        {
            ans.push_back(res);
            return;
        }
        // 选左括号

        if (l < n)
        {

            res.push_back('(');
            dfs(l + 1, r, n, res);
            res.pop_back();
        }
        if (l > r)
        {
            res.push_back(')');
            dfs(l,r+1,n,res);
            res.pop_back();
        }
    }

};
int main(){
    Solution s;
    vector<string> ans = s.generateParenthesis(1);
    for(auto i =ans.begin();i!=ans.end();i++){
        cout<<*i<<endl;
    }
    
}