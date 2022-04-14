class Solution
{
    public:
    TreeNode* searchBST(TreeNode* root, int target)
    {
        if (!root)
            return NULL;
        
        if (target == root->val)
            return root;
        
        if (target < root->val)
            return searchBST(root->left, target);
        else
            return searchBST(root->right, target);
    }
};