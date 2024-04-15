#include <bits/stdc++.h>

using namespace std;

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

private:
    struct NodeComparator
    {
        bool operator()(const ListNode *a, const ListNode *b)
        {
            return a->val > b->val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        if (lists.size() == 0)
        {
            return NULL;
        }

        priority_queue<ListNode *, vector<ListNode *>, NodeComparator> pq;

        for (ListNode *list : lists)
        {
            while (list != NULL)
            {
                pq.push(list);
                // cout<<list->val<<endl;
                list = list->next;
            }
            // cout<<"------"<<endl;
        }

        // cout<<"Sale"<<endl;

        if (pq.empty())
        {
            return NULL;
        }

        ListNode *head = pq.top();
        ListNode *current = head;
        pq.pop();

        while (!pq.empty())
        {
            // cout<<pq.top()->val<<endl;
            current->next = pq.top();
            current = current->next;
            pq.pop();
            current->next = NULL;
        }

        // cout<<"termina"<<endl;
        return head;
    }
};