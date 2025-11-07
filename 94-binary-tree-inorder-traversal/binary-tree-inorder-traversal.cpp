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
                          //   BASIC SOLUTION

    // void helper(TreeNode* root,vector<int>& ans){
    //     if(!root)
    //         return;
    //     helper(root->left,ans);
    //     ans.push_back(root->val);
    //     helper(root->right,ans);
    // }


    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     helper(root,ans);
    //     return ans;
        
    // }
    vector<int> inorderTraversal(TreeNode* root) {
                                        // MORRIS TRAVERSAL
        // vector<int> ans;
        // TreeNode* curr=root;
        // while(curr){
        //     if(curr->left==NULL){
        //         ans.push_back(curr->val);
        //         curr=curr->right;
        //     }

        //     else{        // curr->left= exists
        //         TreeNode* temp=curr->left;
        //         while(temp->right && temp->right!=curr){
        //             temp=temp->right;
        //         }
        //         if(temp->right==NULL){
        //             temp->right=curr;
        //             curr=curr->left;
        //         }
        //         else if(temp->right==curr){
        //             temp->right=NULL;
        //             ans.push_back(curr->val);
        //             curr=curr->right;
        //         }
        //     }
        // }
        //     return ans;
                                        // STACK TRAVERSAL
                vector<int> po;

        if(root==NULL)
            return po;
        stack<pair<TreeNode*,int>> st;
        st.push({root,1});
        while(!st.empty()){
            auto it=st.top();
            st.pop();

            if(it.second==1){
                it.second++;
                st.push(it);
                if(it.first->left!=NULL)
                    st.push({it.first->left,1});
            }
            else if(it.second==2){
                po.push_back(it.first->val);
                if(it.first->right)
                    st.push({it.first->right,1});
            }
        }
        return po;
    }
};