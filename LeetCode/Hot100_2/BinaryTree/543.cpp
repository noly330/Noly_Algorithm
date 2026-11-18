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

    int ans = 0;
    int diameterOfBinaryTree(TreeNode *root)
    {
        
        dfs(root);

        return ans;
    }

    int dfs(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int l=0,r=0;
        if(root->left!=nullptr){
            l = dfs(root->left);
        }
        if(root->right!=nullptr){
            r = dfs(root->right);
        }
        ans = max(ans,l+r);  //记录这个节点可以创造的最长直径
        return max(l,r) + 1; //返回这个节点的最深度
    }
};