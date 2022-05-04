class Solution
{
    public:
    set<int> s;
    
    int findSecondMinimumValue(TreeNode* root)
    {
        preorder(root);        
        return (s.size() <= 1)? -1: *prev(s.end());
    }
    
    void preorder(TreeNode* node)
    {
        if (node == nullptr)
            return;
        
        s.insert(node->val);
        if (s.size() > 2)
            s.erase(prev(s.end()));
        
        preorder(node->left);
        preorder(node->right);
    }
};