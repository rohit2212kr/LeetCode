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
    int dia = 0;
    int high(TreeNode* root){
        if(root == NULL) return 0;
        
        int left = high(root->left);
        int right = high(root->right);
        dia = max(dia, left+right);

        return 1+ max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        high(root);
        return dia;
    }
};