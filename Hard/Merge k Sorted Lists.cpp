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
    void sink(int i, vector<int> &list, int n)
    {
        while ((2 * i + 1) < n)
        {
            int smaller = 2 * i + 1;
            if ((2 * i + 2) < n && list[2 * i + 2] < list[smaller])
                smaller = 2 * i + 2;
            if (list[smaller] > list[i])
                break;
            swap(list[i], list[smaller]);
            i = smaller;
        }
    }
    void buildHeap(vector<int> &list)
    {
        int n = list.size();
        for (int i = max(0, n / 2 - 1); i >= 0; --i)
        {
            sink(i, list, n);
        }
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<int> nums;
        for (ListNode *list : lists)
        {
            while (list != NULL)
            {
                nums.push_back(list->val);
                list = list->next;
            }
        }
        buildHeap(nums);
        int n = nums.size();
        ListNode *head, *tail = NULL;
        while (n--)
        {
            if (n == nums.size() - 1)
            {
                head = tail = new ListNode(nums[0]);
            }
            else
            {
                tail->next = new ListNode(nums[0]);
                tail = tail->next;
            }
            swap(nums[0], nums[n]);
            sink(0, nums, n);
        }
        return head;
    }
};