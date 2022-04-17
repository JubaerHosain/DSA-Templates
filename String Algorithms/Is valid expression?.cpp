
bool is_valid(string a) {
    stack<char> s;
 
    for(char c: a) {
        if(c == '(') s.push(')');
        else if(!s.empty() && s.top() == c) s.pop();
        else return false;
    }
 
    return s.empty();
}
