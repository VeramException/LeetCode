class Solution
{
    public:
    TreeNode* prev = nullptr;
    TreeNode* res = nullptr;
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
    {
        inOrder(root, p);
        return res;
    }
    
    void inOrder(TreeNode* node, TreeNode* p)
    {
        if (node == nullptr)
            return;
        
        inOrder(node->left, p);
        
        if (res != nullptr)
            return;
        
        if (prev && prev->val == p->val)
        {
            res = node;
            return;
        }
        prev = node;
        
        if (res != nullptr)
            return;
        inOrder(node->right, p);
    }
};