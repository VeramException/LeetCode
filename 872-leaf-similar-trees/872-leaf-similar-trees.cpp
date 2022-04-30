class Solution
{
    public:
    vector<int> leaves_1;
    vector<int> leaves_2;
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        inorderTraverse(root1, leaves_1);
        inorderTraverse(root2, leaves_2);
     
        return (leaves_1 == leaves_2);
    }
    
    void inorderTraverse(TreeNode* node, vector<int>& leaves)
    {
        if (node == nullptr)
            return;
        
        inorderTraverse(node->left, leaves);
        
        if (node->left == nullptr && node->right == nullptr)
            leaves.push_back(node->val);
        
        inorderTraverse(node->right, leaves);
    }
};