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
class Solution {
public:

    int cal_h(TreeNode* root) {
        int h = 0;

        if (root->left) {
            h = max(h, cal_h(root->left) + 1);
        }

        if (root->right) {
            h = max(h, cal_h(root->right) + 1);
        }

        return h;
    }

    void dfs(TreeNode* root, vector<vector<string>> &res, int h, int r, int c) {
        res[r][c] = to_string(root->val);

        if (root->left) {
            dfs(root->left, res, h, r + 1, c - (1 << (h - r - 1)));
        }
        if (root -> right) {
            dfs(root->right, res, h, r + 1, c + (1 << (h - r - 1)));
        }
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int h = cal_h(root);

        cout << h;

        int m = h + 1, n = (1 << (h + 1)) - 1;
        vector<vector<string>> res(m, vector<string>(n, ""));

        dfs(root, res, h, 0, (n - 1) >> 1);

        return res;
    }
};