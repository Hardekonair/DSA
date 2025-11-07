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
    int dia(TreeNode* root,int& maxd){
        if(root==NULL)
            return 0;
        
        int ld=dia(root->left,maxd);
        int rd=dia(root->right,maxd);

        maxd=max(maxd,ld+rd);

        return 1+max(ld,rd);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxd=0;
        dia(root,maxd);
        return maxd;
        
    }
};