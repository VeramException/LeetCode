class Solution
{
    private:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;    
    TreeNode* prev = new TreeNode(INT_MIN);
    
    public:
    void recoverTree(TreeNode* root)
    {
        recoverTreeUtil(root);
        swap(first->val, second->val);
    }
    
    // Inorder traversal
    void recoverTreeUtil(TreeNode* node)
    {
        if (node == nullptr) return;
        
        recoverTreeUtil(node->left);
        
        if (first == nullptr && prev->val > node->val) first = prev;
        if (first != nullptr && prev->val > node->val) second = node;
        
        prev = node;
        
        recoverTreeUtil(node->right);
    }
};


