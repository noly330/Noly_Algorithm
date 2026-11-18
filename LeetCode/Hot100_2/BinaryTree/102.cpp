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

    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return ans;
        }
        bfs(root);

        return ans;
    }

    void bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);

        while(q.size()){
            vector<int> mid;
            int x = q.size();
            for(int i = 0;i<x;i++){
                TreeNode * current = q.front();
                q.pop();
                if(current == nullptr){
                    continue;
                }
                mid.push_back(current->val);
                if(current->left!=nullptr)
                    q.push(current->left);
                if(current->right!=nullptr)
                q.push(current->right);
                
            }
            ans.push_back(mid);
        }
    }
};