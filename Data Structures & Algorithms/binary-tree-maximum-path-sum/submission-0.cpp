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
    int getMax(TreeNode* node,int &maxsum){
        if(!node) return 0;
        int left = max(0, getMax(node->left, maxsum));
        int right = max(0, getMax(node->right, maxsum));
        maxsum=max(maxsum,node->val+ left+right);
        return node->val+ max(left,right);

    }
public:
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        getMax(root,maxsum);
        return maxsum;
    }
};
