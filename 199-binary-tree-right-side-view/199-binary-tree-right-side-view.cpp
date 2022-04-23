class Solution
{
    public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> res;
        if (root == nullptr)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int siz = q.size();
            while (siz-- > 0)
            {
                TreeNode* node = q.front(); q.pop();
                
                if (siz == 0)
                    res.push_back(node->val);
                
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return res;
    }
};