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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        if(!root){
            return ans;
        }
        bfs(root,ans);

        return ans;
    }

    void bfs(TreeNode* root, vector<int> & ans){
        queue<TreeNode*> q;
        q.push(root);

        while(q.size()){
            stack<TreeNode*> stk;

            int x = q.size();

            //将当前层数的所有节点出队，最后一个出队的就是最右边的节点
            for(int i = 0;i<x;i++){
                TreeNode* now = q.front();
                q.pop();

                stk.push(now);

                if(now->left){
                    q.push(now->left);
                }
                if(now->right){
                    q.push(now->right);
                }

            }
            ans.push_back(stk.top()->val);
        }
    }
};