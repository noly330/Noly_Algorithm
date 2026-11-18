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
        if(root !=nullptr)
            bfs(root);
        return ans;
    }

    void bfs(TreeNode *root){
        queue<TreeNode*> q;
        q.push(root);
        
        ans.push_back({root->val});
        while(q.size()){
            vector<int> mid;
            int x = q.size();
            for(int i =0;i<x;i++){
                TreeNode *now = q.front();
                q.pop();

                if(now->left != nullptr){

                    q.push(now->left);
                    mid.push_back(now->left->val);
                }
                if(now->right != nullptr){

                    q.push(now->right);
                    mid.push_back(now->right->val);
                }
            }
            if(mid.size()>0)
                ans.push_back(mid);
        }
    }
};