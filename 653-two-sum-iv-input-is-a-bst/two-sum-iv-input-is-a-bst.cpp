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

// class bstiterator{
//     stack<TreeNode*> st;

//     // reverse=false=next
//     //reverse=true=before
//     bool reverse=true;

// public:
//     bstiterator(TreeNode* root,bool isreverse){
//         reverse=isreverse;

//         pushall(root);
//     }

//     bool hasnext(){
//         return !st.empty();
//     }

//     int next(){
//         TreeNode* temp=st.top();
//         st.pop()   ;
//         if(reverse)
//             pushall(temp->left);
//         else
//             pushall(temp->right);
        
//         return  temp->val;
//     }

//     void pushall(TreeNode* root){

//         while(root){
//             st.push(root);
//             root=reverse?root->right:root->left;
//         }
//     }
// };


bool preorder(TreeNode* root,unordered_set<int>& st , int k){
    if(root==NULL)
        return false;

    if(st.find(k-root->val)!=st.end())     // NO NEED OF ST.EMPTY()==FASLE CONDITION
        return true;

    st.insert(root->val);

    return preorder(root->left,st,k) || preorder(root->right,st,k);

}

class Solution {
public:

    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
            return false;
        
        // bstiterator l(root,false);    // next iterator
        // bstiterator r(root,true);    // before iterator
        
        // int i=l.next(), j=r.next();
        
        // while(i<j){
        //     if(i+j==k)
        //         return true;
        //     else if(i+j<k)
        //         i=l.next();
        //     else
        //         j=r.next();
        // }
        // return false;

                                    // O(n), O(k)
        
        unordered_set<int> st;
        return preorder(root,st,k);
    }
};