class Solution
{
    public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        int res = 0;
        diameterOfBinaryTreeUtil (root, res);
        return res;
    }
    
    // res - diameter of binary tree with root as 'root'
    // returns 'height of tree'
    int diameterOfBinaryTreeUtil(TreeNode* root, int& res)
    {
        if (root == nullptr)
            return 0;
        
        int leftHeight = diameterOfBinaryTreeUtil(root->left, res);
        int rightHeight = diameterOfBinaryTreeUtil(root->right, res);
        
        res = max (res, leftHeight + rightHeight);
        
        return max (leftHeight, rightHeight) + 1;
    }
};