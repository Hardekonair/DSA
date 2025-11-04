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
        // to check BST,we have to check every  node
                                    // O(n)- min TC
        
        // Inorder of BST= Sorted
        // Morris traversal = check inorder

        TreeNode* curr=root;
        TreeNode* prev=NULL;
        bool ans=true;

        while(curr){
            if(curr->left){
                TreeNode* leftnode=curr->left;

                while(leftnode->right && leftnode->right!=curr)
                    leftnode=leftnode->right;

                if(leftnode->right==NULL){
                    leftnode->right=curr;
                    curr=curr->left;
                }

                else{    // leftnode->right=curr
                    leftnode->right=NULL;
                    if(prev && prev->val>=curr->val)
                        ans= false;
                    prev=curr;
                    curr=curr->right;
                }
            }
            else{
                if(prev && prev->val>=curr->val)
                    ans= false;
                prev=curr;
                curr=curr->right;
            }


        }
        return ans;
    }
};