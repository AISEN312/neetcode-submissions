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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, 0, res);
        return res;
    }
private:
    void dfs(TreeNode* node, int depth, vector<vector<int>>& res) {
        if (!node) return;
        if (depth == static_cast<int>(res.size()))
            res.push_back(vector<int>()); // new level
        res[depth].push_back(node->val);
        dfs(node->left, depth + 1, res);
        dfs(node->right, depth + 1, res);
    }
};
