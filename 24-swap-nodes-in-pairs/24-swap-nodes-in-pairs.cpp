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
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return head;
        if(!head->next)
            return head;
        ListNode* temp1 = head, *temp2 = head->next;
        ListNode* ret = head;
        ListNode* prev = head;
        while(1)
        {
            if(ret == head)
                ret = temp2;
            temp1->next = temp2->next;
            temp2->next = temp1;
            
            temp1 = temp1->next;
            if(!temp1)
                break;
            temp2 = temp1->next;
            if(!temp2)
                break;
            prev->next = temp2;
            prev = temp1;
        }
        return ret;
    }
};