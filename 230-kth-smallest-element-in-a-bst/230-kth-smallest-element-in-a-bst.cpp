class Solution
{
    public:
    int kthSmallest(TreeNode* root, int k)
    {
        int res;
        inOrder(root, k, res);
        return res;
    }
    
    void inOrder(TreeNode* node, int& k, int& res)
    {
        if (node == nullptr)
            return;
        
        inOrder(node->left, k, res);               
        if (--k == 0)
        {
            res = node->val;
            return;
        }        
        inOrder(node->right, k, res);
    }
};