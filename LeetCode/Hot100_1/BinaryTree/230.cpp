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

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<TreeNode*> stk;  //stk是栈对象，存的是指向TreeNode的指针

        dfs(root,stk);

        return stk[k-1]->val;
    }

    void dfs(TreeNode *root,vector<TreeNode*> &stk){
        if(!root)
            return;
        dfs(root->left,stk);

        stk.push_back(root);

        dfs(root->right,stk);
        
    }
};