class Solution
{
    public:    
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        string tree1;
        string tree2;
        
        buildPreorder(root, tree1);
        buildPreorder(subRoot, tree2);
        
        if (tree1.find(tree2) == string::npos)
            return false;
        
        return true;
    }
    
    void buildPreorder(TreeNode* root, string& s)
    {
        if (root == nullptr)
        {
            s += ",#";
            return;
        }
        
        s += "," + to_string(root->val);
        buildPreorder(root->left, s);        
        buildPreorder(root->right, s);
    }
};