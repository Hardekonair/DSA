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
    ListNode* deleteDuplicates(ListNode* head) {
       // 1 - PUT IN ARRAY, REMOVE DUPLICATE, RECREATE LL
       // 2 - ATTACK NODES TO DUMMY NODE, MOVE FORWARD UNTIL DUMMY->TEMP->VAL==POINTER, IF DIFF ATTACH, CONT.
       // 3 - TAKE 2 POINTER, START,SKIP REPEATED, ATTACH, SKIP REPEATED,CONTINUE

        if(head==NULL)
            return head;
        ListNode* p1,*p2;
        
        p1=head,p2=head->next;
        while(p2!=NULL){
            if(p2->val==p1->val){
                ListNode* t=p2;

                p2=p2->next;
                p1->next=p2;

                t->next=NULL;
                delete t;
            }
            else{
                p1=p1->next;
                p2=p2->next;
            }

        }
        return head;
    }
};