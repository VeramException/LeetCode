class Solution
{
    public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
    {
        if (root == nullptr || p == nullptr)
            return nullptr;
        
        TreeNode* res = nullptr;
        
        while (root != nullptr)
        {
            if (root->val <= p->val)
                root = root->right;
            else
            {
                res = root;
                root = root->left;
            }
        }
        
        return res;
    }
};