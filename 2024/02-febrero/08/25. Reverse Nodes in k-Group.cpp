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

    int ListNodeSize(ListNode* head){
        ListNode* temp = head;
        int pos = 0;

        while(temp!=NULL){
            pos++;
            temp = temp->next;
        }

        return pos;
    }

    void reverse(
        ListNode*& head,
        ListNode*& prev,
        ListNode*& prevBegin,
        ListNode*& beginReverse,
        int k
        ){
        
        ListNode* nextNode = NULL;
        ListNode* current = beginReverse;

        for(int i=0;i<k && current!=NULL;i++){
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        if(prevBegin!=NULL){
            prevBegin->next = prev;
        }
        else{
            head = prev;
        }


        beginReverse->next = current;
    


    }

    void nextRange(
        ListNode*& prevBegin,
        ListNode*& beginReverse,
        int k
    ){
        ListNode* current = beginReverse->next;
        for(int i=0;i<k && current !=NULL;i++){
            prevBegin = beginReverse;
            beginReverse = current;
            current = current->next;
        }
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        int n = ListNodeSize(head);
        int endHere = n-(n%k);

        //cout<<endHere<<endl;

        if(n==0 || k==1){
            return head;
        }

        ListNode* prev = NULL;
        ListNode* prevBegin = NULL;
        ListNode* beginReverse = head;

        for(int i=0;i<endHere;i+=k){
            //cout<<head->val<<" ";
            reverse(
                head,
                prev,
                prevBegin,
                beginReverse,
                k
            );        

        nextRange(
            prevBegin,
            beginReverse,
            k
        );
       
        }

        return head;
    }
};