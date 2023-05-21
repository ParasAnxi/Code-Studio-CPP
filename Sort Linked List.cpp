#include <bits/stdc++.h> 
/****************************************************

    Following is the class structure of the Node class:

    class Node {
    public:
	int data;
	Node *next;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
}

*****************************************************/

Node* sortLL(Node* head) 
{
	
    Node *temp1 = head, *temp2;
    while (temp1 != NULL)
    {
        temp2 = head;
 
        while (temp2->next != NULL)
        {
            if (temp2->data > temp2->next->data)
            {
                swap(temp2->data , temp2->next->data);
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return head;
	/*
   int zeroCnt = 0;
   int oneCnt = 0;
   int twoCnt=0;
   Node* temp = head;
	while(temp!=NULL){
		if(temp->data==0){
			zeroCnt++;
		}
		else if(temp->data==1){
			oneCnt++;
		}
		else{
			twoCnt++;
		}
		temp=temp->next;
	}
	temp = head;
	while(temp!=NULL){
		if(zeroCnt!=0){
			temp->data=0;
			zeroCnt--;
		}
		else if(oneCnt!=0){
			temp->data=1;
			oneCnt--;
		}
		else{
			temp->data=2;
			twoCnt--;
		}
		temp=temp->next;
	}
	return head;
*/
}