#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

       class Node 
        { 
        public:
            int data;
            Node *next;
            Node(int data) 
            {
               this->data = data;
              this->next = NULL;
            }
        };

*****************************************************************/
int getLength(Node* head){
    int len = 0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}
Node* getMid(Node* &head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    if(head->next->next==NULL){
        return head->next;
    }
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
    }
    return slow;
}
Node *findMiddle(Node *head) {
    // int length = getLength(head);
    // int ans = (length/2);
    // Node* temp = head;
    // int cnt = 0;
    // while(cnt<ans){
    //     temp=temp->next;
    //     cnt++;
    // }
    // return temp;

    return getMid(head);
}