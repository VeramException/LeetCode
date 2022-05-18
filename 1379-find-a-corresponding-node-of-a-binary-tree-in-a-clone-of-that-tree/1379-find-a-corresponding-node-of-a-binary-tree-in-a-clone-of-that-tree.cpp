class Solution
{
    public:
    TreeNode* clonedTarget = nullptr;
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* originalTarget)
    {        
        dfs(original, cloned, originalTarget);
        return clonedTarget;
    }
    
    void dfs(TreeNode* originalNode, TreeNode* clonedNode, TreeNode* originalTarget)
    {
        if (originalNode == nullptr || clonedNode == nullptr)
            return;
        
        if (originalNode == originalTarget)
        {
            clonedTarget = clonedNode;
            return;
        }
        
        if (clonedTarget == nullptr)
            dfs(originalNode->left, clonedNode->left, originalTarget);
        if (clonedTarget == nullptr)
            dfs(originalNode->right, clonedNode->right, originalTarget);
    }
};