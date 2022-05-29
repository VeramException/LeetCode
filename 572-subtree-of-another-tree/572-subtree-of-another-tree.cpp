class Solution
{
    public:    
    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        string arr1;
        string arr2;
        
        buildPreorder(root, arr1);
        buildPreorder(subRoot, arr2);
        
        if (arr1.find(arr2) == string::npos)
            return false;
        
        return true;
    }
    
    void buildPreorder(TreeNode* root, string& arr)
    {
        if (root == nullptr)
        {
            arr += "#";
            return;
        }
        
        arr += "<" + to_string(root->val) + ">";
        buildPreorder(root->left, arr);        
        buildPreorder(root->right, arr);
    }
};