class Solution
{
    public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* originalTarget)
    {
        TreeNode* clonedTarget = nullptr;
        dfs(original, cloned, originalTarget, clonedTarget);
        return clonedTarget;
    }
    
    void dfs(TreeNode* originalNode, TreeNode* clonedNode, TreeNode* originalTarget, TreeNode* &clonedTarget)
    {
        if (originalNode == nullptr || clonedNode == nullptr)
            return;
        
        if (originalNode == originalTarget)
        {
            clonedTarget = clonedNode;
            return;
        }
        
        if (clonedTarget == nullptr)
            dfs(originalNode->left, clonedNode->left, originalTarget, clonedTarget);
        if (clonedTarget == nullptr)
            dfs(originalNode->right, clonedNode->right, originalTarget, clonedTarget);
    }
};