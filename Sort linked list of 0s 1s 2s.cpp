/********************************
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

********************************/
void populate(Node* &tail ,Node* curr){
    tail->next = curr;
    tail = curr;
}
Node *sortList(Node *head){
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneTail = oneHead;
    Node* twoTail = twoHead;

    Node* curr = head;
    
    while(curr!=NULL){
        int value = curr->data;
        if(value==0){
            populate(zeroTail,curr);
        }
        else if(value==1){
            populate(oneTail,curr);
        }
        else if(value==2){
            populate(twoTail,curr);
        }
        curr=curr->next;
    }
    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }
    else{
        zeroTail->next = twoHead->next;
    }
    oneTail->next = twoHead->next;
    twoTail->next = NULL;
    head = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    return head;
}
