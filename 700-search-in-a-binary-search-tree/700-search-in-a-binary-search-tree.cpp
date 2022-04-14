

//
// (2) - Iterative Solution
//
class Solution
{
    public:
    TreeNode* searchBST(TreeNode* root, int target)
    {
        while (root != NULL)
        {
            if (target == root->val)
                return root;
            
            if (target < root->val)
                root = root->left;
            else
                root = root->right;
        }
        return root;
    }
};