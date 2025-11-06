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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mpp;    // vertical, level, elements
        queue<pair<TreeNode*,pair<int,int>>> q;  // root, vertical, level
        q.push({root,{0,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            int v=it.second.first, l=it.second.second;
            mpp[v][l].insert(node->val);    //Since this is a multiset,we have to insert val
            if(node->left)
                q.push({node->left,{v-1,l+1}});
            if(node->right)
                q.push({node->right,{v+1,l+1}});
            
        }
        vector<vector<int>> ans;
        for(auto it:mpp){
            vector<int>lvl;
            for(auto ti:it.second){
                lvl.insert(lvl.end(),ti.second.begin(),ti.second.end());
            }
            ans.push_back(lvl);
        }
        return ans;
        
                                // NOT SUITABLE FOR ARRANGING ELEMENT AT SAME VERTICAL
        // map<int,vector<int>>mpp;
        // queue<pair<TreeNode*,int>> q;
        // q.push({root,0});
        // while(!q.empty()){
        //     auto temp=q.front();
        //     q.pop();
        //     TreeNode* node=temp.first;
        //     int line=temp.second;

        //     mpp[line].push_back(node->val);
        //     if(node->left)
        //         q.push({node->left,line-1});
        //     if(node->right)
        //         q.push({node->right,line+1});
        // }
        // vector<vector<int>> ans;
        // for(auto it:mpp){
        //     sort(it.second.begin(),it.second.end());
        //     ans.push_back(it.second);
        // }
        // return ans;
        
    }
};