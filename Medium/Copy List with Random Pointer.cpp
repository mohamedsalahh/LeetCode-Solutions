/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        map<int, Node *> mp1;
        map<Node *, int> mp2;
        Node *temp = head;
        Node *tail2 = NULL, *head2 = NULL;

        int idx = 0;
        while (temp != NULL)
        {
            if (head2 == NULL)
                head2 = tail2 = new Node(temp->val);
            else
            {
                tail2->next = new Node(temp->val);
                tail2 = tail2->next;
            }
            mp1[idx] = tail2;
            mp2[temp] = idx;
            temp = temp->next;
            idx++;
        }

        mp1[idx] = NULL;
        mp2[NULL] = idx;

        temp = head;
        tail2 = head2;
        idx = 0;
        while (temp != NULL)
        {
            int x = mp2[temp->random];
            tail2->random = mp1[x];

            temp = temp->next;
            tail2 = tail2->next;
            idx++;
        }
        return head2;
    }
};