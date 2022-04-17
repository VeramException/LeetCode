/* // RECURSIVE  */
class Solution
{
    public:
    TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL)
    {
        if (!root)
            return tail;
        
        TreeNode* res = increasingBST(root->left, root);
        root->left = NULL;
        root->right = increasingBST(root->right, tail);
        return res;
    }
};

/*  --- ITERATIVE ---
//
class Solution
{
    public:
    TreeNode* increasingBST(TreeNode* root)
    {
        TreeNode* head = new TreeNode(0);
        TreeNode* pre = head;
        
        stack<TreeNode*> s;
        while (root || !s.empty())
        {
            while (root)
            {
                s.push(root);
                root = root->left;
            }
            
            root = s.top(); s.pop();
            pre->right = root;
            pre = pre->right;
            root->left = nullptr;
            root = root->right;
        }
        
        return head->right;
    }
};
*/