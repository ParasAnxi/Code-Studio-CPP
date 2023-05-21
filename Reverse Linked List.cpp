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
Node* reverse(Node* &head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node* List = reverse(head->next);
	head->next->next=head;
	head->next = NULL;
	return List;
}
// void reverse(Node* &head,Node* prev,Node* curr){
// 	if(curr==NULL){
// 		head=prev;
// 		return;
// 	}
// 	reverse(head,curr,curr->next);
// 	curr->next = prev;
// }
Node* reverseLinkedList(Node *head)
{
	// Node* prev=NULL;
	// Node* curr = head;
	// reverse(head,prev,curr);
	
	return reverse(head);
	
	/*if(head==NULL || head->next==NULL){
		return head;
	}
	Node* prev = NULL;
	Node* curr = head;
	Node* forward = NULL;

	while(curr!=NULL){
		forward = curr->next;
		curr->next = prev;
		prev=curr;
		curr = forward;
	}
	return prev;*/
}

