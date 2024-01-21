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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        int num = 0;

        if(list1!=NULL && list2!=NULL){
            //cout<<"1"<<endl;
            if(list1->val<list2->val){
                num = list1->val;
                list1 = list1->next;
            }
            else{
                num = list2->val;
                list2 = list2->next;
            }
        }
        else if(list1==NULL){
            //cout<<"2"<<endl;
            return list2;
        }
        else{
            //cout<<"3"<<endl;
            return list1;
        }

        ListNode* answer = new ListNode(num);
        ListNode* current = answer;

        while(list1!=NULL && list2!=NULL){

            if(list1->val<list2->val){
                current->next = new ListNode(list1->val);

                current = current->next;
                list1 = list1->next;

            }
            else{
                current->next = new ListNode(list2->val);

                current = current->next;
                list2 = list2->next;
            }
        }

        while(list1!=NULL ){
            current->next = new ListNode(list1->val);

            current = current->next;
            list1 = list1->next;
        }

        while(list2!=NULL){
            current->next = new ListNode(list2->val);

            current = current->next;
            list2 = list2->next;
        }

        return answer;
    }
};