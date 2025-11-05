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
    vector<int> rightSideView(TreeNode* root) {

        if(root==NULL)
            return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
                                        // Unusual traversal - right to left
        // while(!q.empty()){
        //     int size=q.size();
        //     ans.push_back(q.front()->val);
        //     for(int i=0;i<size;i++){
        //         TreeNode* temp=q.front();
        //         q.pop();
        //         if(temp->right)
        //             q.push(temp->right);
        //         if(temp->left)
        //             q.push(temp->left);
        //     }
                                        // STd traversal- left to right
        while(!q.empty()){
            int size=q.size();
            int lastval=0;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                lastval=temp->val;
                if(temp->left)  
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            ans.push_back(lastval);
        }
        
        return ans;
    }
};