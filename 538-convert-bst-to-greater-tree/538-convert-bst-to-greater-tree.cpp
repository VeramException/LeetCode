class Solution
{
    public:
    TreeNode* convertBST(TreeNode* root)
    {
        int sum = 0;
        convertBSTUtil(root, sum);
        return root;
    }
    
    int convertBSTUtil(TreeNode* node, int& sum)
    {
        if (node == nullptr)
            return sum;
     
        node->val += convertBSTUtil(node->right, sum);
        
        return convertBSTUtil(node->left, node->val);
    }
};