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
    void markparent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent){
        if(root==NULL)
            return;
        parent[root]=NULL;

        TreeNode* temp=root;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            
            if(cur->left){
                parent[cur->left]=cur;
                q.push(cur->left);
            }
            if(cur->right){
                parent[cur->right]=cur;
                q.push(cur->right);
            }

        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        markparent(root,parent);
        unordered_map<TreeNode*,int> vis;

        queue<TreeNode*>q;

        q.push(target);
        vis[target]=1;

        int count=0;

        while(!q.empty()){
            int size=q.size();

            if(count==k){
                break;
            }

            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->right && !vis[temp->right]){
                    q.push(temp->right);
                    vis[temp->right]=1;
                }
                if(temp->left && !vis[temp->left]){
                    q.push(temp->left);
                    vis[temp->left]=1;
                }
                if(parent[temp] && !vis[parent[temp]]){
                    q.push(parent[temp]);
                    vis[parent[temp]]=1;
                }

            }
            count++;
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};