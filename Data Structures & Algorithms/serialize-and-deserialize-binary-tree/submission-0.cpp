class Codec {
public:

    void serializeDFS(TreeNode* root, string& res)
    {
        if (!root)
        {
            res += "#_";
            return;
        }

        res += to_string(root->val);
        res += "_";

        serializeDFS(root->left, res);
        serializeDFS(root->right, res);
    }

    string serialize(TreeNode* root)
    {
        string res;

        serializeDFS(root, res);

        return res;
    }

    TreeNode* deserializeDFS(vector<string>& nodes, int& idx)
    {
        if (nodes[idx] == "#")
        {
            idx++;
            return nullptr;
        }

        TreeNode* root =
            new TreeNode(stoi(nodes[idx++]));

        root->left = deserializeDFS(nodes, idx);
        root->right = deserializeDFS(nodes, idx);

        return root;
    }

    TreeNode* deserialize(string data)
    {
        vector<string> nodes;

        string cur;

        for (char ch : data)
        {
            if (ch == '_')
            {
                nodes.push_back(cur);
                cur.clear();
            }
            else
            {
                cur += ch;
            }
        }

        int idx = 0;

        return deserializeDFS(nodes, idx);
    }
};