/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        // DFS时候要判断一下，左子树和右子树如果有一个不存在，那要取另一边的树高+1
        if(!left || !right)
            return left+right+1;
        return min(left,right)+1;
    }
};