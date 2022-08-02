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
    bool isPalindrome(ListNode* head) {
        int cnt = 0;
        ListNode *temp1 = head;
        while(temp1)
        {
            cnt++;
            temp1 = temp1->next; 
        }
        int mid = cnt / 2 + 1;
        temp1 = head;
        ListNode *temp2 = NULL;
        for(int i = 0; i < mid-1; ++i)
        {
            ListNode *temp3 = temp1->next;
            temp1->next = temp2;
            temp2 = temp1;
            temp1 = temp3;
        }
        if(cnt & 1)
            temp1 = temp1->next;
        for(int i = 0; i < mid-1; ++i)
        {
            if(temp2->val != temp1->val)
                return false;
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        return true;
    }
};