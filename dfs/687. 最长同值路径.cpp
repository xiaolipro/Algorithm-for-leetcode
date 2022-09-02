/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
给定一个二叉树的 root ，返回 最长的路径的长度 ，这个路径中的 每个节点具有相同值 。 这条路径可以经过也可以不经过根节点。

两个节点之间的路径长度 由它们之间的边数表示。
 */
class Solution {
public:
    int res = 0;
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;

        int l = dfs(root->left), r = dfs(root->right);
        int x = 0, y = 0;
        if (root->left && root->left->val == root->val) x = l + 1;
        if (root->right && root->right->val == root->val) y = r + 1;
        res = max(res, x + y);
        return max(x, y);
    }
};