#define ll long long

class Solution {
private: 
    vector<string> ans;
    
    void dfs(int i, string path, string &str, ll sum, int target, ll prev) {
        if(i == str.length()) {
            if(sum == target)
                ans.push_back(path);
            return;
        } 
        
        for(int j = i; j < str.length(); j++) {
            // skip leading zero number
            if(j > i && str[i] == '0')
                return;
            ll num = stoll(str.substr(i, j-i+1));
            if(i == 0) 
                dfs(j+1, path + to_string(num), str, num, target, num);
            else {
                dfs(j+1, path + "+" + to_string(num), str, sum + num, target, num);
                dfs(j+1, path + "-" + to_string(num), str, sum - num, target, -num);
                dfs(j+1, path + "*" + to_string(num), str, (sum - prev) + (prev * num) , target, prev * num);
            }
        }
    }
    
public:
    vector<string> addOperators(string str, int target) {
        dfs(0, "", str, 0, target, 0);
        return ans;
    }
};