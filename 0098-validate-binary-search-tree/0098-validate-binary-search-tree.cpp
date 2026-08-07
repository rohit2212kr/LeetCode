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

    bool fun(TreeNode *curr, long long mini, long long maxi){

        if(curr == NULL) return true;

        if(curr->val >= maxi || curr->val <= mini){
            return false;
        }

        bool left = fun(curr->left, mini, curr->val);
        bool right = fun(curr->right, curr->val, maxi);
        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        
        return fun(root, LLONG_MIN, LLONG_MAX );
    }

};