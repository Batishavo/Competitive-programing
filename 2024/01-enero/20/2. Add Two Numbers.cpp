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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int sum = l1->val+l2->val;
        int carry = sum%10;
        int remaind = sum/10;

        ListNode* answer = new ListNode(carry);
        ListNode* current = answer;

        l1 = l1->next;
        l2 = l2->next;

        while(l1 != NULL && l2!=NULL){
            
            sum = l1->val+l2->val+remaind;

            carry = sum%10;
            remaind = sum/10;
        
            current->next = new ListNode(carry);

            current = current->next;
            l1 = l1->next;
            l2 = l2->next;

        }

        while(l1 != NULL ){
            int sum = l1->val + remaind;
            current->next = new ListNode(sum%10);
            remaind = sum/10;

            current = current->next;
            l1 = l1->next;
            
        }

        while(l2 != NULL){
            int sum = l2->val + remaind;
            current->next = new ListNode(sum%10);
            remaind = sum/10;

            current = current->next;
            l2 = l2->next;

        }

        while(remaind>0){
            current->next = new ListNode(remaind%10);
            remaind/=10;

            current = current->next;
        }

        return answer;
    }
};