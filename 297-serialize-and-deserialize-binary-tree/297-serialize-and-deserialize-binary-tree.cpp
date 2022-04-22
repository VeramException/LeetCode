class Codec
{
    public:
    string DELIMITER = ",";
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if (root == nullptr)
            return "#";
        return to_string(root->val) + DELIMITER + serialize(root->left) + DELIMITER + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        return deserializeUtil(data);
    }
    
    TreeNode* deserializeUtil(string& data)
    {
        if (data[0] == '#')
        {
            if (data.size() > 1)
                data = data.substr(2);
            return nullptr;
        }
        
        int pos = data.find(DELIMITER);
        int val = stoi(data.substr(0, pos));
        data = data.substr(pos+1);
        
        TreeNode* node = new TreeNode(val);
        node->left  = deserializeUtil(data);
        node->right = deserializeUtil(data);
        return node;
    }
};
