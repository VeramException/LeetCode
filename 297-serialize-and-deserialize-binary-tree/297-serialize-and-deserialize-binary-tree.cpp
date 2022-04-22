class Codec
{
    public:
    char DELIMITER = ',';
    
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
        stringstream ss(data);
        return deserializeUtil(ss);
    }
    
    TreeNode* deserializeUtil(stringstream& dataStream)
    {
        string val;
        getline(dataStream, val, DELIMITER);   // if dataStream = "12,45", after this call, val = "12" and dataStream = "45"
        
        if (val == "#")
            return nullptr;
        
        TreeNode* node = new TreeNode(stoi(val));
        node->left  = deserializeUtil(dataStream);
        node->right = deserializeUtil(dataStream);
        return node;
    }
};
