#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
/*Node* merge(Node* left, Node* right)
{
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;
    Node* ans = new Node(-1);
    Node* temp = ans;
    while(left != NULL && right != NULL)
    {
        if(left->data < right->data)
        {
            temp->child = left;
            temp = left;
            left = left->child;
        }
        else
        {
            temp->child = right;
            temp = right;
            right = right->child;
        }
    }
    if(left != NULL)
    {
        temp->child = left;
        temp = left;
        left = left->child;
    }
    if(right != NULL)
    {
         temp->child = right;
         temp = right;
         right = right->child;
    }
    return ans->child;
}*/
Node* merge(Node* a, Node* b){
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    Node* result;
 
    if (a->data < b->data) {
        result = a;
        result->child = merge(a->child, b);
    }
    else {
        result = b;
        result->child = merge(a, b->child);
    }
    result->next = NULL;
    return result;
}
Node* flattenLinkedList(Node* head) 
{
    if(head == NULL)
        return head;
    
   Node* down = head;
   Node* right = head->next;
   down->next = NULL;
   right = flattenLinkedList(right);
    
    Node* ans = merge(down, right);
    return ans;
}
