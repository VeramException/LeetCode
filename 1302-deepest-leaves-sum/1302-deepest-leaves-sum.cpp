class Solution
{
    public:
    int deepest = 0;
    int deepestSum = 0;
    
    int deepestLeavesSum(TreeNode* root)
    {
        deepestLeavesSumUtil(root, 0);
        return deepestSum;
    }
    
    void deepestLeavesSumUtil(TreeNode* node, int level)
    {
        if (node == nullptr)
            return;
        
        if (deepest == level)
        {
            deepestSum += node->val;
        }
        
        if (deepest < level)
        {
            deepest = level;
            deepestSum = node->val;
        }
        
        deepestLeavesSumUtil(node->left, level+1);
        deepestLeavesSumUtil(node->right, level+1);
    }
};