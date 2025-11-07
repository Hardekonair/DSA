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
    int calcsum(TreeNode* root,int& maxsum){
        if(root==NULL)
            return 0;
        // if(!root->left && !root->right)
        //     return root->val;
        int leftsum=calcsum(root->left,maxsum);
        int rightsum=calcsum(root->right,maxsum);

        if(leftsum<0)
            leftsum=0;
        if(rightsum<0)
            rightsum=0;

        maxsum=max(maxsum,root->val+leftsum+rightsum); 

        return root->val+max(leftsum,rightsum);
    }
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        calcsum(root,maxsum);
        return maxsum;
        
    }
};