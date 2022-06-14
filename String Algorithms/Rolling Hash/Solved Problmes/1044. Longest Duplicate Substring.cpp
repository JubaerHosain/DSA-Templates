class Solution {
    long mod = 1e9+7;
    
    string find_duplicate(string &s, int k) {
        long base = 26, pow = 1, hash = 0;
        for(int i = 0; i < k; i++) {
            hash = (hash*base + (s[i]-'a')) % mod;
            if(i > 0) 
                pow = (pow * 26) % mod;
        }
        
        // starting indices of substring
        unordered_map<long, vector<int>> mp; 
        mp[hash].push_back(0);
        
        for(int i = k; i < s.length(); i++) {
            hash = (hash - (s[i-k]-'a') * pow) % mod;
            hash = (hash + mod) % mod;
            hash = (hash*base + (s[i]-'a')) % mod;
            
            if(mp.count(hash)) {
                string curr = s.substr(i-k+1, k);
                for(auto &it: mp[hash]) {
                    string tmp = s.substr(it, k);
                    if(curr == tmp)
                        return curr;
                }
            }
            
            mp[hash].push_back(i-k+1);
        }
        
        return "";
    }
    
public:
    string longestDupSubstring(string s) {
        int low = 1, high = s.size();
        string ans = "";
        
        while(low <= high) {
            int mid = (low + high) / 2;
            string duplicate = find_duplicate(s, mid);
            if(duplicate.length() != 0) {
                ans = duplicate;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};

