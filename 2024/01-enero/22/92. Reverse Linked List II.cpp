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
    ListNode* eraseFirst(ListNode* arr){

        arr = arr->next;    
        ListNode* answer = new ListNode(arr->val);
        ListNode* current = answer;
        arr = arr->next;

        while(arr!=NULL){
            current->next = new ListNode(arr->val);
            arr=arr->next;
            current=current->next;
        } 

        return answer;

    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head == NULL){
            return head;
        }

        stack<int> nums;
        
        bool insertNums = false;

        ListNode* answer = new ListNode();
        ListNode* current = answer;

        int pos = 1;

        while(head!=NULL && pos<=right){

            if(pos>= left && pos <= right){
                nums.push(head->val);
            }
            else{
                current->next = new ListNode(head->val);
                //cout<<"beggining ="<<head->val<<endl;
                current = current->next;
            }   
            head = head->next;
            pos++;
        }

        while(!nums.empty()){
            
            //cout<<"midle = "<<nums.top()<<endl;

            current->next = new ListNode(nums.top());
            nums.pop();
            current = current->next;
        }

        while(head!=NULL){
            current->next = new ListNode(head->val);
            //cout<<"end ="<<head->val<<endl;
            current = current->next;
            head = head->next;
        }

        return eraseFirst(answer);

    }
};