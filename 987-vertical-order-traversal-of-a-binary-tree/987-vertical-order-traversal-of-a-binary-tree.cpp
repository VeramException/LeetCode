class Solution
{
    public:
    map<int, vector<multiset<int>>> m;
    
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        queue<pair<TreeNode*, int>> q;  // <node, VerticalLevel>
        q.push({root, 0});
        while (!q.empty())
        {
            unordered_map<int, multiset<int>> currRowResult;
            
            int siz = q.size();
            while (siz-- > 0)
            {
                TreeNode* node = q.front().first;
                int vLevel = q.front().second;
                q.pop();
                
                currRowResult[vLevel].insert(node->val);
                
                if (node->left)
                    q.push({node->left,  vLevel-1});
                if (node->right)
                    q.push({node->right, vLevel+1});
            }
            
            for (auto iter: currRowResult)
                m[iter.first].push_back(iter.second);
        }
        
        vector<vector<int>> res;
        for (auto const& [k,v]: m)
        {
            vector<int> levelRes;
            for (multiset<int> s: v)
            {
                for (int val: s)
                    levelRes.push_back(val);
            }
            res.push_back(levelRes);
        }
        return res;
    }
};