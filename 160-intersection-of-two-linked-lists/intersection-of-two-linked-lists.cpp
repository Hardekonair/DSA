/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int>mpp;
        while(headA){
            // if(headA){
                mpp[headA]++;
            // }
            headA=headA->next;
        }
        while(headB){
            // if(headB){
                if(mpp[headB]>0)
                    return headB;
                else
                    mpp[headB]++;
            // }
            headB=headB->next;
        }
        return nullptr;
    }
};