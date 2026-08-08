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
    void solve(TreeNode *curr, vector<int> &abc){
        if(curr == NULL) return;

        solve(curr->left, abc);
        abc.push_back(curr->val);
        solve(curr->right, abc);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        solve(root, res);
        return res[k-1];
    }
};