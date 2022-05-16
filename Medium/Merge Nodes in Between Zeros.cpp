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
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *tail = head;

        while (tail != NULL)
        {

            if (tail->next->val == 0)
            {
                if (tail->next->next == NULL)
                {
                    ListNode *temp = tail->next;
                    tail->next = NULL;
                    delete temp;
                }

                tail = tail->next;
                continue;
            }
            tail->val += tail->next->val;
            ListNode *temp = tail->next;
            tail->next = temp->next;
            delete temp;
        }

        return head;
    }
};