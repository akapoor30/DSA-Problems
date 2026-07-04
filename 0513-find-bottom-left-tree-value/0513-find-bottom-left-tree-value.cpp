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
    int ans = 0;
    int l = 0;
    void f(TreeNode* root, int h) {
        // root check
        if(!root)
            return;
        f(root->left, h + 1);
        // check for left
        if(h > l) {
            ans = root->val;
            l = h;
        }
        f(root->right, h + 1);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL){
            return root->val;
        }
        f(root, 0);
        return ans;

    }
};