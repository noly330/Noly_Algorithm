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

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if(root == nullptr){
            return false;
        }

        return dfs(root->left,root->right);
    }

    bool dfs(TreeNode* a,TreeNode* b){
        if(a == nullptr && b == nullptr){
            return true;
        }
        else if((!a && b) || (a && !b)){
            return false;
        }
        if(a->val != b->val){
            return false;
        }

        return dfs(a->left,b->right) && dfs(a->right,b->left);
    }
};