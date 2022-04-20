class BSTIterator
{
    public:
    stack<TreeNode*> s;
    
    BSTIterator(TreeNode* root)
    {
        while (root != nullptr)
        {
            s.push(root);
            root=root->left;
        }
    }
    
    int next()
    {
        int res = s.top()->val;
        
        TreeNode* temp = s.top(); s.pop();
        if (temp->right != nullptr)
        {
            temp = temp->right;
            while (temp != nullptr)
            {
                s.push(temp);
                temp=temp->left;
            }
        }
        
        return res;
    }
    
    bool hasNext()
    {
        return !s.empty();
    }
};
