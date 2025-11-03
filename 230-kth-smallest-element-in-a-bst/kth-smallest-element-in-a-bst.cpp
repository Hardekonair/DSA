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
    int kthSmallest(TreeNode* root, int k) {
        int cnt=1;
        int ans=-1;
        TreeNode* dummy=root;
        while(dummy){
            if(dummy->left==NULL){
                if(cnt==k)
                    ans=dummy->val;
                cnt++;
                dummy=dummy->right;
            }
            else{
                TreeNode* leftnode=dummy->left;
                while(leftnode->right && leftnode->right!=dummy){
                    leftnode=leftnode->right;
                }
                if(leftnode->right==NULL){
                    leftnode->right=dummy;
                    dummy=dummy->left;
                }
                else{
                    leftnode->right=NULL;
                    if(cnt==k)
                        ans=dummy->val;
                    cnt++;
                    dummy=dummy->right;
                }
            }
        }
        return ans;
    }
};