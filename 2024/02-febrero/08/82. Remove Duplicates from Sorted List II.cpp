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
    ListNode* deleteDuplicates(ListNode* head) {

        if(head==NULL){
            return NULL;
        }
        if(head->next == NULL){
            return head;
        }

        ListNode* current = head->next;
        ListNode* prev = head;
        ListNode* prevAnt = NULL;
        ListNode* tmp;
        ListNode* aux;

        while(current!=NULL){
            if(current->val == prev->val){
                tmp = current->next;
                while(tmp!=NULL && tmp->val == prev->val){
                    tmp=tmp->next;
                }
                if(tmp==NULL ){
                    if(prevAnt==NULL){
                        return NULL;
                    }
                    else{
                        current = NULL;
                        prevAnt->next = NULL;
                        return head;
                    }
                    
                }

                if(prevAnt!=NULL){
                    prevAnt->next = tmp;    
                }
                else{
                    while(head!=tmp){
                        aux = head->next;
                        head=NULL;
                        head = aux;
                    }
                    
                }

                if(tmp!=NULL){
                    current=tmp->next;
                }
                prev=tmp;
                //current = tmp;
            }
            else{
                current=current->next;
                prev=prev->next;
                if(prevAnt == NULL){
                    prevAnt = head;
                }
                else{
                    prevAnt = prevAnt->next;
                }
            }
        }
        

        return head;
    }
};