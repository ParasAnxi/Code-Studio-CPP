#include <bits/stdc++.h>
using namespace std;
int count(LinkedListNode<int> *head) {
  LinkedListNode<int> *ptr = head;
  int count = 0;
  while (ptr != NULL) {
    count++;
    ptr = ptr->next;
  }
  return count;
}
LinkedListNode<int> *removeKthNode(LinkedListNode<int> *head, int K) {
    if(K==0||head==NULL){
        return head;
    }
    int c=count(head);
    int pos=c-K;
    if(pos==0){
        LinkedListNode<int> *Next=head->next;
        head->next=NULL;
        head=Next;
        return head;
    }
    LinkedListNode<int> *Temp=head;
    for(int i=1;i<pos;i++){
        Temp=Temp->next;
    }
    LinkedListNode<int> *Next=Temp->next;
    Temp->next=Next->next;
    Next->next=NULL;
    delete Next;
    return head;
  
}