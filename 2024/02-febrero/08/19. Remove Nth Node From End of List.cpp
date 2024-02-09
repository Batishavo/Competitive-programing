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

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head==NULL || head->next == NULL){
            return NULL;
        }

        ListNode* current = head;
        ListNode* behind = head;
        int cont = 0;
        int tam = 0;

        while(current!= NULL){
            current=current->next;
            tam++;
            if(cont<=n){
                cont++;
            }
            else{
                behind=behind->next;
            }
        }
        if(tam==n){
            ListNode* temp = head;
            head=head->next;
            temp->next = NULL;
        }
        else{
            behind->next = behind->next->next;
        }
        return head;
    }
};