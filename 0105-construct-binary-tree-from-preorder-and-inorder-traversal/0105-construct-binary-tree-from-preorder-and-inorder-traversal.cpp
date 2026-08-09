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
class Solution
{
public:
    TreeNode* fun(vector<int>& preorder, vector<int>& inorder,
                  int preStart, int preEnd, int inStart, int inEnd)
    {
        if (preStart > preEnd || inStart > inEnd)
        {
            return nullptr;
        }

        int rootValue = preorder[preStart];

        TreeNode* root = new TreeNode(rootValue);

        int rootIndex = inStart;

        while (inorder[rootIndex] != rootValue)
        {
            rootIndex++;
        }

        int leftSize = rootIndex - inStart;

        root->left = fun(preorder, inorder,
                         preStart + 1,
                         preStart + leftSize,
                         inStart,
                         rootIndex - 1);

        root->right = fun(preorder, inorder,
                          preStart + leftSize + 1,
                          preEnd,
                          rootIndex + 1,
                          inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return fun(preorder, inorder,
                   0, preorder.size() - 1,
                   0, inorder.size() - 1);
    }
};