class Solution
{
    public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        if (original == nullptr)
            return nullptr;
        
        if (original == target)
            return cloned;
        
        TreeNode* l = getTargetCopy(original->left,  cloned->left,  target);
        TreeNode* r = getTargetCopy(original->right, cloned->right, target);
        
        return (l != nullptr)? l: r;
    }
};