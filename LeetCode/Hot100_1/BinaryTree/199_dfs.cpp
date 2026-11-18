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

int visited[100];
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        memset(visited,0,sizeof(visited));
        vector<int> ans;
        dfs(root,0,ans);
        return ans;
    }

    void dfs(TreeNode* root, int depth,vector<int> &ans){

        if(root == nullptr)
            return;

        if(visited[depth] == 0 ){
            visited[depth] = 1;
            ans.push_back(root->val);
        }

        //先递归优先访问右子树
        dfs(root->right,depth + 1,ans);

        dfs(root->left, depth + 1 ,ans);

    }
};