bool matches(char top , char ch){
    if((top == '{' && ch == '}') || (top == '(' && ch == ')') || (top == '[' && ch == ']')){
        return true;
    }
    else{
        return false;
    }
}
bool isValidParenthesis(string expression){
    int n = expression.length();
    stack<char> s;

    for(int i = 0 ;i<n ;i++){
        char ch = expression[i];

        if((ch == '{') || (ch == '(') || (ch == '[')){
            s.push(ch);
        }
        else{
            if(!s.empty()){
                char top = s.top();
                if(matches(top , ch)){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(s.empty())
    return true;
    else
    return false;
}