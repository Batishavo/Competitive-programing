#include<bits/stdc++.h>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:

    ListNode* getMid(ListNode* left,ListNode* right){
        
        int cont=0;

        ListNode* current = left;

        while(current!=right){
            cont++;
            current = current->next;
        }

        cont/=2;

        current = left;

        while(cont>0){
            cont--;
            current = current->next;
        }

        return current;

    }

    void paste(ListNode* left,ListNode* mid,ListNode* right){

        //cout<<"cabesales - left:"<<left->val<<" mid:"<<mid->val<<" right: "<<right->val<<endl;
        
        ListNode* realLeft = left;
        ListNode* realRight = right;
        ListNode* realMid = mid;

        queue<int> copy;

        while(
            left!=realMid &&
            mid!=realRight->next
        ){
            
            if(left->val<mid->val){
                copy.push(left->val);
                left=left->next;
            }
            else{
                copy.push(mid->val);
                mid = mid->next;
            }

        }
        while(left!=realMid){
            copy.push(left->val);
            left=left->next;

        }
        while(mid!=realRight->next){
            copy.push(mid->val);
            mid = mid->next;
        }

        
        while(
            realLeft!=realRight->next
        ){
            //cout<<realLeft->val<<"--"<<copy.front()<<endl;
            realLeft->val = copy.front();
            realLeft = realLeft->next;
            copy.pop();
        }

    }



    void merge(ListNode* left,ListNode* right){

        if(left==right){
            return ;
        }

        ListNode* mid = getMid(left,right);
        
        merge(left,mid);
        merge(mid->next,right);

        paste(left,mid->next,right);


        return;

    }

    ListNode* sortList(ListNode* head) {
        
        if(head==NULL){
            return head;
        }

        ListNode* tail = head;

        while(tail->next!=NULL){
            tail = tail->next;
        }
        
        merge(head,tail);
        //cout<<getMid(head,tail)->val;
        return head;    
    }
};