#include <bits/stdc++.h> 
void sortStack(stack<int>& s , int e){
    if(s.empty() || (!s.empty() && s.top()<e)){
        s.push(e);
        return;
    }
    int n = s.top();
    s.pop();
    sortStack(s,e);
    s.push(n);
}
void sortStack(stack<int> &stack){
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();
    sortStack(stack);
    sortStack(stack,num);
}