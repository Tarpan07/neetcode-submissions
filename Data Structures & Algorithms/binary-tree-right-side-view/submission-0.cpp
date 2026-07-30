/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>view;

        if (!root) return view;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            bool first=true;

            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                if(first){
                    view.push_back(node->val);
                    first=false;
                }
                level.push_back(node->val);
                if (node->right)
                    q.push(node->right);
                if (node->left)
                    q.push(node->left);

                
            }
;
        }

        return view;
    }
};
