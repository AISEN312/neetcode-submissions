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
    bool isValidBST(TreeNode* root) {
        return validRange(root,
                          std::numeric_limits<long long>::min(),
                          std::numeric_limits<long long>::max());
    }

private:
    bool validRange(TreeNode* node, long long low, long long high) {
        if (node == nullptr) return true;
        long long v = node->val;
        if (v <= low || v >= high) return false;
        return validRange(node->left, low, v) &&
               validRange(node->right, v, high);
    }
};
