/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ListNode *normalSpeed = head;
        ListNode *fastSpeed = head;

        while(normalSpeed != NULL && fastSpeed != NULL && fastSpeed->next != NULL){

            normalSpeed = normalSpeed->next;
            fastSpeed = fastSpeed->next->next;
            //fastSpeed = fastSpeed->next;

            if(normalSpeed == fastSpeed){
                return true;
            }
        }

        return false;

    }
};