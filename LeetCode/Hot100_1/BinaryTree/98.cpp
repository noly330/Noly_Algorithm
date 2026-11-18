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
    bool isValidBST(TreeNode* root) {
        // 使用 LONG_MIN/LONG_MAX 处理边界情况
        return check(root, LONG_MIN, LONG_MAX);
    }

    bool check(TreeNode* root, long long minVal, long long maxVal) {
        if (root == nullptr) return true;
        
        if(root->val <= minVal || root->val >= maxVal)
            return false;

        return check(root->left,minVal,root->val)  && check(root->right,root->val,maxVal);
    }
};