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
    void func(TreeNode* node, int x,int &cnt){
        if(!node) return;
        if (node->val >= x)
            cnt++;
        x = max(x, node->val);
        func(node->left,x,cnt);
        func(node->right,x,cnt);
    }
public:
    int goodNodes(TreeNode* root) {
        int cnt=0;
        func(root,INT_MIN,cnt);
        return cnt;
    }
};
