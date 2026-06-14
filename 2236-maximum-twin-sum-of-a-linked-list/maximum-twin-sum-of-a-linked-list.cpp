/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* temp=head;
        vector<int>list;
        while(temp){
            list.push_back(temp->val);
            temp=temp->next;
        }
        int n=list.size();
        int i=0,j=n-1;
        int ans=0;
        while(i<j){
            ans=max((list[i]+list[j]),ans);
            i++;
            j--;
        }
        return ans;
    }
};