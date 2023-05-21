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

Node *removeDuplicates(Node *head){

    unordered_map<int,bool> m;
    Node* curr = head;
    while(curr->next!=NULL){
        m[curr->data]=true;
        if(m[curr->next->data]==true){
            Node* next_next = curr->next->next;
            Node* toDel = curr->next;
            delete(toDel);
            curr->next=next_next;
        }
        else
            curr=curr->next;
    }
    return head;
}
