#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//TODO：学习空间复杂度O(1)的解法
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if(root == nullptr)
            return;
        vector<TreeNode*> ans;
        dfs(root,ans);
        for(int i = 0;i < ans.size() - 1;i++){
            ans[i]->left = nullptr;
            ans[i]->right = ans[i+1];
        }
        ans[ans.size() - 1]->left = nullptr;
        ans[ans.size() - 1]->right = nullptr;
    }

    void dfs(TreeNode * root,vector<TreeNode*> &ans){
        if(root == nullptr)
            return;
        
        ans.push_back(root);
        dfs(root->left,ans);
        dfs(root->right,ans);
    }
};