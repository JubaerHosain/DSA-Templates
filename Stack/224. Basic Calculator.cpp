class Solution {
public:
    int calculate(string str) {
        stack<int> stk;
        int sum = 0, sign = 1;
        
        int n = str.length();
        for(int i = 0; i < n; i++) {
            char ch = str[i];
            if(ch == '+') {
                sign = 1;
            } else if(ch == '-') {
                sign = -1;
            } else if(isdigit(ch)) {
                int num = 0;
                while(i < n && isdigit(str[i])) {
                    num = num * 10 + (str[i] - '0');
                    i += 1;
                }
                i -= 1;
                num = sign * num;
                sum += num;
                sign = 1;
            } else if(ch == '(') {
                stk.push(sum);
                stk.push(sign);
                sum = 0;
                sign = 1;
            } else if(ch == ')') {
                // previous sign
                sum = sum * stk.top();
                stk.pop();
                // previous sum
                sum += stk.top();
                stk.pop();
                sign = 1;
            }
        }
        
        return sum;
    }
};


