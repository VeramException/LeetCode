class Solution
{
    public:
    vector<int> leaves_1;
    vector<int> leaves_2;
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        dfs(root1, leaves_1);
        dfs(root2, leaves_2);
     
        return (leaves_1 == leaves_2);
    }
    
    void dfs(TreeNode* node, vector<int>& leaves)
    {
        if (node == nullptr)
            return;
        
        dfs(node->left, leaves);
        dfs(node->right, leaves);
        
        if (node->left == nullptr && node->right == nullptr)
            leaves.push_back(node->val);
    }
};