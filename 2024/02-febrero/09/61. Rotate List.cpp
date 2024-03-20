// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (head == nullptr)
        {
            return nullptr;
        }

        if (head->next == nullptr)
        {
            return head;
        }

        ListNode *current = head;
        ListNode *tail = head;
        int n = 1;

        while (tail->next != nullptr)
        {
            tail = tail->next;
            n++;
        }
        k = k % n;

        while (k--)
        {
            tail->next = head;
            tail = head;
            while (head->next != tail)
            {
                head = head->next;
            }
            while (tail->next != head)
            {
                tail = tail->next;
            }
            tail->next = nullptr;
        }

        return head;
    }
};