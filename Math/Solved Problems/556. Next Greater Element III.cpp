class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        
        int i = str.length()-1;
        for(; i > 0; i--)
            if(str[i] > str[i-1]) break;
        
        if(i == 0) 
            return -1;
        
        i -= 1;
        
        // just greater than str[i]
        int j = i+1;
        for(int k = i+1; k < str.length(); k++)
            if(str[k] < str[j] and str[k] > str[i])
                j = k;
        
        swap(str[i], str[j]);
        
        // sort asceding order from i+1 to n
        sort(str.begin()+i+1, str.end());
        
        long long num = stol(str);
        
        return num <= INT_MAX ? (int)num :  -1;
    }
};



