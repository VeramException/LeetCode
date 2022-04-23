// *********************
// ******** BFS ********
// *********************
/*class Solution 
{
    public:
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> result;
        if (!root)
            return result;
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int qSiz = q.size();
            while (qSiz>0)
            {
                TreeNode* node = q.front(); q.pop();
                
                if (qSiz == 1)
                   result.push_back(node->val); 
                
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                
                qSiz--;
            }
            
        }
        return result;
    }
}; */

// *********************
// ******** DFS ******** O(1) space - nice solution
// *********************
class Solution
{
    public:
    vector<int> res;
    vector<int> rightSideView(TreeNode* root) 
    {
        dfs(root, 0);
        return res;
    }
    
    void dfs(TreeNode* node, int level)
    {
        if (node == nullptr)
            return;
        
        if (res.size() == level)
            res.push_back(node->val);
        
        dfs(node->right, level+1);
        dfs(node->left, level+1);
    }
};
















