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
    bool isValidBST(TreeNode* root) {
        return f(root,LLONG_MIN,LLONG_MAX);
        
    }
    
    bool f(TreeNode* root, long long minval,long long maxval){
        if(root==NULL)return 1;
        if(root->val>=maxval || root->val<=minval){return 0;}
        
        return f(root->left,minval,root->val) && f(root->right,root->val,maxval);
    }
};