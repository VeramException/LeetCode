class Solution
{
    public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> res;
        
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty())
        {
            vector<int> currLevel;
            int q_siz = q.size();
            while (q_siz-- > 0)
            {
                TreeNode* node = q.front(); q.pop();
                currLevel.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            res.push_back(currLevel);
        }
        
        return res;
    }    
};