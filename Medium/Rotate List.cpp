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
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return head;

        ListNode *tail = head;
        int sz = 1;

        while (tail->next != NULL)
        {
            tail = tail->next;
            sz++;
        }
        tail->next = head;

        k %= sz;
        sz -= k;

        for (int i = 0; i < sz - 1; ++i)
            head = head->next;

        tail = head;
        head = head->next;
        tail->next = NULL;

        return head;
    }
};