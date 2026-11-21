class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> result;
        queue<TreeNode*> q;

        q.push(root); 
        
        while (!q.empty()) { 
            int qLen = q.size(); 
            vector<int> level; 
            for (int i = 0; i < qLen; i++) { 
                TreeNode* n = q.front();
                q.pop();
                if (n) { 
                    level.push_back(n->val);    
                    q.push(n->left); 
                    q.push(n->right);
                } 
            }
            if (!level.empty()) { 
                result.push_back(level);
            }
        }
        return result;
    }
};
