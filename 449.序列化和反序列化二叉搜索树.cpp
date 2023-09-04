/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <string>
#include <vector>
#include <cstddef>

class Codec
{
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode *root)
    {
        std::string result;
        serializeImpl(root, result);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(std::string data)
    {
        TreeNode *root = nullptr;
        auto buffer = reinterpret_cast<uint8_t*>(data.data());
        for (int i = 0; i < data.size(); i += 2)
        {
            uint16_t val = buffer[i];
            val <<= 8;
            val |= buffer[i + 1];
            deserializeImpl(root, val);
        }
        return root;
    }

private:
    void serializeImpl(TreeNode *node, std::string &buffer)
    {
        if (node == nullptr)
            return;
        int val = node->val;
        buffer.push_back(static_cast<char>(val >> 8));
        buffer.push_back(static_cast<char>(val & 0x00ff));
        serializeImpl(node->left, buffer);
        serializeImpl(node->right, buffer);
    }

    void deserializeImpl(TreeNode *&node, int val)
    {
        if (node == nullptr)
        {
            node = new TreeNode(val);
            return;
        }
        if (node->val > val)
        {
            deserializeImpl(node->left, val);
        }
        else
        {
            deserializeImpl(node->right, val);
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end
