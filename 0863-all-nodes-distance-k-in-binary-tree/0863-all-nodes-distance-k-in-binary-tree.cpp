/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        q.push(root);
        map<TreeNode*,TreeNode*> mp;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                mp[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                mp[node->right] = node;
            }
        }

        queue<TreeNode*> q1;

        map<TreeNode*, int> vis;
        q1.push(target);
        int dis = 0;
        vis[target]++;


        while(!q1.empty() ){
            if(dis ==k)break;
            dis++;
            int size = q1.size();
            for(int i =0;i<size;i++){
                TreeNode* node = q1.front();
                q1.pop();
                if(node->left && !vis[node->left]){
                    q1.push(node->left);
                    vis[node->left]++;
                
                }
                if(node->right && !vis[node->right]){
                    q1.push(node->right);
                    vis[node->right]++;
                    

                }
                TreeNode* temp = mp[node];

                if(mp[node] && !vis[mp[node]]){
                    q1.push(mp[node]);
                    vis[mp[node]]++;
                }
            }
            

        }

        vector<int> ans;

        while(!q1.empty()){
            TreeNode* node = q1.front();
            q1.pop();

            ans.push_back(node->val);
        }
        return ans;
    }
};