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
    int totalsum(TreeNode* root){
        if(root==NULL)
            return 0;

        int leftsum=totalsum(root->left);
        int rightsum=totalsum(root->right);

        return root->val+leftsum+rightsum;
    }

    int helper(TreeNode* root,int totalsum, long& maxp){
        if(root==NULL)
            return 0;

        int leftsubtreesum=helper(root->left,totalsum,maxp);
        int rightsubtreesum=helper(root->right,totalsum,maxp);
        long subsum=root->val+leftsubtreesum+rightsubtreesum;
        long restsum=totalsum-subsum;

        maxp=max(maxp,subsum*restsum);

        return subsum;

    }
    int maxProduct(TreeNode* root) {
        int sum=totalsum(root);
        long maxp=INT_MIN;
        helper(root,sum,maxp);
        return maxp%(1000000007);

    }
};