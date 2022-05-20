class Solution
{
    public:
    int res = 0;
    
    int maxAncestorDiff(TreeNode* root)
    {
        dfs(root);        
        return res;
    }
    
    pair<int, int> dfs(TreeNode* root)
    {
        if (root == nullptr)
            return {INT_MAX, INT_MIN};
        
        auto [lMin, lMax] = dfs(root->left);
        auto [rMin, rMax] = dfs(root->right);
        
        int currMin = min({root->val, lMin, rMin});
        int currMax = max({root->val, lMax, rMax});
        
        res = max ({res, abs(currMax-root->val), abs(currMin-root->val)});
        
        return {currMin, currMax};
    }
};