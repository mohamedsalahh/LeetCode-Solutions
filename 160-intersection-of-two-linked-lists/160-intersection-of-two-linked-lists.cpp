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
        map<ListNode*, bool> vis;
        while(headA)
        {
            vis[headA] = 1;
            headA = headA->next;
        }
        while(headB)
        {
            if(vis[headB])
                return headB;
            headB = headB->next;
        }
        return NULL;
    }
};