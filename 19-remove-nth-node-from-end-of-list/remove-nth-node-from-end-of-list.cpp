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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL){
            head = NULL;
            return NULL;
        }
        ListNode* p = head;
        int size = 0;
        while(p!=NULL){
            p = p->next;
            size++;
        }
        if(size-n-1<0)
            return head->next;
        int i = 0;
        p=head;
        while(i<size-n-1){
            p = p->next;
            i++;
        }
        p->next = p->next->next;
        return head;
    }
};