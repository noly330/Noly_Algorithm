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
//TODO:学习前缀和解法
class Solution
{
public:
    // 从root当起点，
    int rootSum(TreeNode *root, long long targetSum)
    {
        if (!root)
        {
            return 0;
        }
        int ret = 0;
        if (root->val == targetSum)
        {
            ret++;
        }
        ret += rootSum(root->left, targetSum - root->val);
        ret += rootSum(root->right, targetSum - root->val);
        return ret;
    }
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
        {
            return 0;
        }

        //以root为起点，到达target的结果
        int ans = rootSum(root, targetSum);

        //往下求子树里
        ans += pathSum(root->left, targetSum); 
        ans += pathSum(root->right, targetSum);

        return ans;
    }
};