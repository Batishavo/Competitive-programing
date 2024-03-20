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

    void f1(ListNode* head,int x){

        ListNode* current = head;
        ListNode* posConcat = NULL;
        ListNode* tmp = NULL;
        ListNode* aux = NULL;

        while(current!=NULL){
            if(current->val == x){
                if(posConcat == NULL){
                    posConcat = current;
                }
                else{
                    tmp = posConcat->next;
                    aux = current->next;
                    posConcat->next = current;
                    current->next = tmp;
                    tmp->next = aux;
                    posConcat = current;
                  
                }
            }
            
            current = current->next;
            
        }


    }

    ListNode* partition(ListNode* head, int x) {
        
        f1(head,x);
        return head;      
    }
};