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
        string str;
        getline(dataStream, str, DELIMITER);
        
        if (str == "#")
            return nullptr;
        
        TreeNode* node = new TreeNode(stoi(str));
        node->left  = deserializeUtil(dataStream);
        node->right = deserializeUtil(dataStream);
        return node;
    }
};
