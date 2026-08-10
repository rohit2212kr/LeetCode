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
    int fun(TreeNode* curr, int &maxsum){
        if(curr == NULL) return 0;

        int left = fun(curr->left, maxsum);
        int right = fun(curr->right, maxsum);

        left = max(0, left);
        right = max(0, right);

        maxsum = max(maxsum, curr->val+ left + right);

        return curr->val + max(left, right);


    }
    int maxPathSum(TreeNode* root) {
        int maxsum = INT_MIN;

        fun(root, maxsum);
        return maxsum;
    }
};