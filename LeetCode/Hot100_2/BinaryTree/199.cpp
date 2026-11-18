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
    vector<int> rightSideView(TreeNode *root)
    {
        return bfs(root);
    }

    vector<int> bfs(TreeNode* root){
        vector<int> ans;
        if(!root)
            return ans;
            
        queue<TreeNode*> q;
        q.push(root);
        

        while(q.size()){
            
            int x = q.size();
            for(int i = 0;i<x;i++){
                TreeNode* node = q.front();
                q.pop();
                if(i == 0){
                    ans.push_back(node->val);
                }
                if(node->right!=nullptr)
                    q.push(node->right);
                if(node->left)
                    q.push(node->left);
            }
            
        }

        return ans;
    }
};