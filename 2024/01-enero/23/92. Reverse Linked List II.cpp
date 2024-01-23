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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left==right || head == NULL){
            return head;
        }

        ListNode* prevBegin = NULL;
        ListNode* current = head;

        for(int i=1;i<left && current!=NULL;++i){
            prevBegin = current;
            current = current->next;
        }

        ListNode* prev = NULL;
        ListNode* nextNode = NULL;
        ListNode* beginReverse = current;

        for(int i=left;i<=right && current !=NULL;i++){
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        if(prevBegin!=NULL){
            prevBegin->next = prev;
        }
        else{
            head=prev;
        }

        beginReverse->next = current;
        return head;
    }
};