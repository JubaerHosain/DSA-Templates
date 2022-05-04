class Solution {
private:
    bool is_operator(char ch) {
        return ch == '!' || ch == '|' || ch == '&';
    }
    
    char not_operation(char ch) {
        return ch == 't' ? 'f' : 't';
    }
    
    char or_operation(char ch1, char ch2) {
        if(ch1 == 't' || ch2 == 't')
            return 't';
        return 'f';
    }
    
    char and_operation(char ch1, char ch2) {
        if(ch1 == 't' && ch2 == 't')
            return 't';
        return 'f';
    }
    
public:
    bool parseBoolExpr(string expression) {
        stack<char> chars;
        stack<char> operators;
        
        int n = expression.length();
        for(int i = 0; i < n; i++) {
            char ch = expression[i];
            if(is_operator(ch)) {
                operators.push(ch);
            } else if(ch != ',' && ch != ')') {
                 chars.push(ch);
            } else if(ch == ')') {
                char tmp = chars.top();
                while(chars.top() != '(') {
                    if(operators.top() == '!') 
                        tmp = not_operation(chars.top());
                    else if(operators.top() == '|') 
                        tmp = or_operation(chars.top(), tmp);
                    else if(operators.top() == '&') 
                        tmp = and_operation(chars.top(), tmp);
                    chars.pop();
                }
                chars.pop();
                operators.pop();
                chars.push(tmp);
            }
        }
        
        return chars.top() == 't' ? true : false;
    }
};


