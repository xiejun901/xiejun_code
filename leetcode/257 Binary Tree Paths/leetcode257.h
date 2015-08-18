#include"leetcode.h"
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        auto result = path(root);
        for (auto &str : result)
            reverse(str.begin(), str.end());
        return result;
    }
    vector<string> path(TreeNode* root) {
        vector<string> result;
        if (root == nullptr)
            return result;
        if (root->left == nullptr && root->right == nullptr)
        {
            auto s = to_string(root->val);
            reverse(s.begin(), s.end());
            return vector<string>(1, s);
        }
        if (root->left != nullptr)
        {
            auto temp = path(root->left);
            result.insert(result.end(), temp.begin(), temp.end());
        }
        if (root->right != nullptr)
        {
            auto temp = path(root->right);
            result.insert(result.end(), temp.begin(), temp.end());
        }
        for (auto &str : result)
        {
            str.insert(str.end(), { '>','-' });
            auto s = to_string(root->val);
            reverse(s.begin(), s.end());
            str += s;
        }
        return result;
    }
};