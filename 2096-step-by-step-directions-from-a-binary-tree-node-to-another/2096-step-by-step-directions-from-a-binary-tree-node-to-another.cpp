class Solution
{
    public:
    
    string rootToStart;
    string rootToDest;
    string sub;
    
    string getDirections(TreeNode* root, int startValue, int endValue)
    {
        // find out paths from 'root to start' and 'root to dest'
        find(root, startValue, endValue);
        
        if (rootToStart == "")
            return rootToDest;
        if (rootToDest == "")
            return string(rootToStart.size(), 'U');
        
        // Remove top nodes from root, that have same route (same value) i.e., find LCA.
        int i=0;
        while (i < rootToStart.size() && i < rootToDest.size() && rootToStart[i] == rootToDest[i])
            i++;
        
        return string(rootToStart.size()-i, 'U') + rootToDest.substr(i);
    }
    
    void find (TreeNode* node, int startValue, int endValue)
    {
        if (node == nullptr)
            return;
        
        if (node->val == startValue)
            rootToStart = sub;
        if (node->val == endValue)
            rootToDest = sub;
        
        if (node->left)
        {
            sub += "L";
            find(node->left, startValue, endValue);
            sub.pop_back();
        }
        if (node->right)
        {
            sub += "R";
            find(node->right, startValue, endValue);
            sub.pop_back();
        }        
    }
};