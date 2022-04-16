class Solution
{
    public:
    TreeNode* convertBST(TreeNode* root)
    {
        convertBSTUtil(root, 0);
        return root;
    }
    
    int convertBSTUtil(TreeNode* node, int sum)
    {
        if (node == nullptr)
            return sum;
     
        node->val += convertBSTUtil(node->right, sum);
        
        return convertBSTUtil(node->left, node->val);
    }
};