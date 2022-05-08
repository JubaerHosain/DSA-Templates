class Solution {
public:
    string minRemoveToMakeValid(string str) {
        stack<pair<char, int>> stk;
        
        for(int i = 0; i < str.length(); i++) {
            char ch = str[i];
            if(ch == '(') 
                stk.push({ch, i});
            else if(ch == ')') {
                if(stk.empty() || stk.top().first == ')')
                    stk.push({ch, i});
                else if(stk.top().first == '(')
                    stk.pop();
            }
        }
        
        while(!stk.empty()) {
            int i = stk.top().second;
            str[i] = '-';
            stk.pop();
        }
        
        string ans;
        for(char ch: str) 
            if(ch != '-') ans.push_back(ch);
        
        return ans;
    }
};