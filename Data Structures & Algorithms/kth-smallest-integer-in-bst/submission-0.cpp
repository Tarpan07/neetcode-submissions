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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr=root;
        priority_queue<int> pq;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            if (pq.size() < k) {
                pq.push(node->val);
            }
            else if (node->val < pq.top()) {
                pq.pop();
                pq.push(node->val);
            }
            

            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }
        return pq.top();
    }
};
