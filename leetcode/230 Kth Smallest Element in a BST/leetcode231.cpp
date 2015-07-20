class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
		 inorder(root);
		 return vec[k - 1];
	 }
	 void inorder(TreeNode* root)
	 {
		 if (root != nullptr)
		 {
			 inorder(root->left);
			 vec.push_back(root->val);
			 inorder(root->right);
		 }
	 }
	 vector<int> vec;
};