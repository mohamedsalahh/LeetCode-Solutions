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
        int sz = 0;
        ListNode* temp1 = head;
        while(temp1)
        {
            temp1 = temp1->next;
            sz++;
        }
        temp1 = head;
        n = sz - n - 1;
        if(n == -1)
        {
            head = head->next;
            delete temp1;
            return head;
        }
        while(n--)
            temp1 = temp1->next;
        
        ListNode* temp2 = temp1->next;
        temp1->next = temp1->next->next;
        delete temp2;
        return head;
    }
};