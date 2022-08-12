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
        int cntA = 0, cntB = 0;
        ListNode *tempA = headA, *tempB = headB;
        
        while(tempA)
        {
            cntA++;
            tempA = tempA->next;
        }
        while(tempB)
        {
            cntB++;
            tempB = tempB->next;
        }
        
        for(int i = 0; i < cntA - min(cntA, cntB); ++i)
            headA = headA->next;
        
        for(int i = 0; i < cntB - min(cntA, cntB); ++i)
            headB = headB->next;
        
        while(headA)
        {
            if(headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
