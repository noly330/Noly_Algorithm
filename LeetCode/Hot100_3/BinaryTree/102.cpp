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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int x = q.size();
            vector<int> mid;
            while(x){
                TreeNode* now = q.front();
                q.pop();
                if(now!=nullptr){
                    q.push(now->left);
                    q.push(now->right);
                    mid.push_back(now->val);
                }

                x--;
            }
            if(mid.size())
                ans.push_back(mid);
        }

        return ans;
    }
};