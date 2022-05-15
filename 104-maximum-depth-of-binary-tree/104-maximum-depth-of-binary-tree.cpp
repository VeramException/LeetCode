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
    int maxDepth(TreeNode* root)
    {
        return maxDepthUtil(root, 0);
    }
    
    int maxDepthUtil(TreeNode* node, int level)
    {
        if (node == nullptr)
            return level;
        
        
        int lLevel = maxDepthUtil(node->left, level+1);
        int rLevel = maxDepthUtil(node->right, level+1);
        return max(lLevel, rLevel);
    }
};