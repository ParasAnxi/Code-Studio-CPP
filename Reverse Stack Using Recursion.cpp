void insertAtBottom(stack<int>& s ,int e){
    if(s.empty()){
        s.push(e);
        return;
    }
    int num = s.top();
    s.pop();
    insertAtBottom(s,e);
    s.push(num);
}
void reverseStack(stack<int> &stack) {
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack,num);
}