class Solution
{
    public:
    int closest;
    
    int closestValue(TreeNode* root, double target)
    {
        closest = root->val;
        binarySearch(root, target);
        return closest;
    }
    
    void binarySearch(TreeNode* node, double& target)
    {
        if (node == nullptr)
            return;
       
        if (abs(closest - target) > abs(node->val - target))
            closest = node->val;
        
        if (target < node->val)
            binarySearch(node->left, target);
        else
            binarySearch(node->right, target);
    }
};