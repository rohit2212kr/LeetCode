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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        if(root == NULL){
            root = new TreeNode(val);
            return root;
        }
        while(true){
            if(val < curr->val && curr->left != NULL) {
                curr = curr->left;
            }
            else if(val>curr->val && curr->right != NULL) {
                curr = curr->right;
            }
            else if(val < curr->val && curr->left == NULL){
                curr->left = new TreeNode(val);
                break;
            }
            else{
                curr->right = new TreeNode(val);
                break;
            }
        }
        return root;

    }
};