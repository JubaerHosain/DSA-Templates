class Solution {
private:
    bool lower_case(char ch) {
        return ch >= 'a' && ch <= 'z';
    }
    
    bool upper_case(char ch) {
        return ch >= 'A' && ch <= 'Z';
    }
    
    bool number(char ch) {
        return ch >= '0' && ch <= '9';
    }
    
public:
    string countOfAtoms(string formula) {
        int n = formula.length();
        stack<pair<string, int>> stk;
        for(int i = 0; i < n; i) {
            char ch = formula[i];
            if(ch == '(') {
                i += 1;
                string str(1, ch);
                stk.push({str, 0});
            } else if(upper_case(ch)) {
                i += 1;
                string atom;
                atom.push_back(ch);
                while(i < n && lower_case(formula[i])) 
                    atom.push_back(formula[i++]);
                
                string num;
                while(i < n && number(formula[i]))
                    num.push_back(formula[i++]);
                
                if(num.length() == 0) 
                    stk.push({atom, 1});
                else
                    stk.push({atom, stoi(num)});
            } else if(ch == ')') {
                i += 1;
                int cnt = 1;
                string num;
                while(i < n && number(formula[i]))
                    num.push_back(formula[i++]);
                if(num.length() > 0)
                    cnt = stoi(num);
                
                stack<pair<string, int>> tmp;
                while(!stk.empty() && stk.top().first != "(") {
                    pair<string, int> pii = stk.top();
                    stk.pop();
                    pii.second *= cnt;
                    tmp.push(pii);
                }
                
                if(!stk.empty()) 
                    stk.pop();
                
                while(!tmp.empty()) {
                    stk.push(tmp.top());
                    tmp.pop();
                }
            }
        }
        
        // sorted by key
        map<string, int> mp;
        while(!stk.empty()) {
            mp[stk.top().first] += stk.top().second;
            stk.pop();
        }
        
        string ans;
        for(auto it: mp) {
            ans += (it.second > 1 ? it.first + to_string(it.second) : it.first);
        }
        
        return ans;
    }
};