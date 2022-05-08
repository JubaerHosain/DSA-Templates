class Solution {
private
    bool is_valid(string &str) {
        stackchar stk;
        for(char ch str) {
            if(ch == '(') 
                stk.push(')');
            else if(ch == ')') {
                if(stk.empty()  stk.top() != ch)
                    return false;
                stk.pop();
            }
        }
        
        return stk.empty();
    }
    
    void get_answer(string &str, int mn, setstring &unique) {
        if(mn == 0) {
            if(is_valid(str))
                unique.insert(str);
            return;
        }
        
        for(int i = 0; i  str.length(); i++) {
            string left = str.substr(0, i);
            string right = str.substr(i+1);
            string tmp = left + right;
            get_answer(tmp, mn-1, unique);
        }
    }
    
    int min_remove(string &str) {
        stackchar stk;
        
        for(int i = 0; i  str.length(); i++) {
            char ch = str[i];
            if(ch == '(') 
                stk.push(ch);
            else if(ch == ')') {
                if(stk.empty()  stk.top() == ')')
                    stk.push(ch);
                else if(stk.top() == '(')
                    stk.pop();
            }
        }
        
        return stk.size();
    }
    
public
    vectorstring removeInvalidParentheses(string str) {
        int mn = min_remove(str);
        
        setstring unique;
        get_answer(str, mn, unique);
        
        vectorstring ans;
        for(string s unique)
            ans.push_back(s);
        
        return ans;
    }
};









