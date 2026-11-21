class Solution {
    vector<int> res;

public:
    vector<int> inorderTraversal(TreeNode* root) {
        indorder(root); 
        return res;

    }

private: 
    void indorder(TreeNode* node) { 
        if (!node) return;
        indorder(node->left);
        res.push_back(node->val); 
        indorder(node->right);
    }
};