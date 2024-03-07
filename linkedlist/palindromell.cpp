#include<bits/stdc++.h>
using namespace std;
/// brute force solution:
/* 
1) store the elements in stack or vector and remove the elements while checking 
2) st.push(),st.pop(),st.top()!=(p->val) then the given linked list is not a palindrome:

  */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* p;
        p=head;
        // int count=0;
        // vector<int> a;
        stack<int> st;
        while(p!=NULL){
            // count++;
            // a.push_back(p->val);
            st.push(p->val);
            p=p->next;
        }
        // for(int i=0;i<count;i++){
        //     if(a[i]!=a[count-1-i])return false;
        // }
        p=head;
        while(p!=NULL){
            if(st.top()!=(p->val))return false;
            st.pop();
            p=p->next;
        }
        
        return true;
        
        
    }
};
// OPTIMUM SOLUTION:

class optimum {
public:
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL || head->next==NULL)return true;
        // this is the method od optimising the code:
        
        ListNode* slow;
        ListNode* fast;
        slow=head;
        fast=head;
        int count=0;
        ListNode* p=head;
        
        while(p!=NULL){
            p=p->next;
            count++;
        }
        
        
        while(fast!=NULL && (fast->next)!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        ListNode* reverse_half=reverse(slow);
        // there is no need of any calculation for the odd number
        // problem is with only even number:
        if(count%2 ==0)
        {
            
            // slow->next=NULL;
            count=count/2;
            slow=head;
            for(int i=1;i<count;i++){
                slow=slow->next;
            }
            slow->next=NULL;
        }
        
        while(head!=NULL){
            if(head->val != reverse_half->val)return false;
            head=head->next;
            reverse_half=reverse_half->next;
        }
        
        
        
        return true;
        
        
    }

private: 
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL)return head;
        ListNode* prev=NULL;
        ListNode* cur=head;
        ListNode* temp;
        while(cur!=NULL){
            temp=cur->next;
            cur->next=prev;
            prev=cur;
            cur=temp;
        }
        return prev;
    }
    
};

