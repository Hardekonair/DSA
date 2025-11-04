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

    bool helper(TreeNode* root,long lowbound,long upbound){
        if(root==NULL)
            return true;
        if( root->val>=upbound || root->val<=lowbound)
            return false;
        return helper(root->left,lowbound,root->val) && 
        helper(root->right,root->val,upbound);
    }

    bool isValidBST(TreeNode* root) {
                        // to check BST,we have to check every  node
        
                                    // Inorder of BST= Sorted
                                    // Morris traversal = check inorder

                                    // O(n)- min TC , O(1)
        // TreeNode* curr=root;
        // TreeNode* prev=NULL;
        // bool ans=true;

        // while(curr){
        //     if(curr->left){
        //         TreeNode* leftnode=curr->left;

        //         while(leftnode->right && leftnode->right!=curr)
        //             leftnode=leftnode->right;

        //         if(leftnode->right==NULL){
        //             leftnode->right=curr;
        //             curr=curr->left;
        //         }

        //         else{    // leftnode->right=curr
        //             leftnode->right=NULL;
        //             if(prev && prev->val>=curr->val)
        //                 ans= false;
        //             prev=curr;
        //             curr=curr->right;
        //         }
        //     }
        //     else{
        //         if(prev && prev->val>=curr->val)
        //             ans= false;
        //         prev=curr;
        //         curr=curr->right;
        //     }


        // }
        // return ans;


                            // recursive code O(n),O(n)

        return helper(root,LONG_MIN,LONG_MAX);
    }
};