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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;
        vector<int> v;
        ListNode *temp = head, *temp2, *temp3;
        for (int i = 1; i <= right; ++i)
        {
            if (i >= left)
                v.push_back(temp->val);
            if (i == left)
                temp2 = temp;
            if (i == right)
                temp3 = temp;
            temp = temp->next;
        }
        int n = right - left;
        for (int i = n; i >= 0; --i)
        {
            temp2->val = v[i];
            temp2 = temp2->next;
        }
        return head;
    }
};