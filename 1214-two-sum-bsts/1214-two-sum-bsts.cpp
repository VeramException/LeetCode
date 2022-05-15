class Solution
{
    public:
    unordered_set<int> s;
    
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target)
    {   
        loadUniqueValues(root1);
        return dfs(root2, target);
    }
    
    void loadUniqueValues(TreeNode* node)
    {
        if (node == nullptr)
            return;
        
        s.insert(node->val);
        loadUniqueValues(node->left);
        loadUniqueValues(node->right);
    }
    
    bool dfs(TreeNode* node, int target)
    {
        if (node == nullptr)
            return false;
        
        if (s.count(target-(node->val)) > 0)
            return true;
        
        return dfs(node->left, target) || dfs(node->right, target);
    }
};
