class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<vector<int>> mp(26);
        
        // first character -> words
        for(int i = 0; i < words.size(); i++) {
            int mask = 0;
            for(char ch: words[i]) {
                int bit = ch - 'a';
                mask = mask | (1<<bit);
            }
            
            vector<bool> used(26, false);
            for(char ch: words[i]) {
                if(used[ch-'a']) continue;
                mp[ch-'a'].push_back(mask);
                used[ch-'a'] = true;
            }
        }
        
        vector<int> ans(puzzles.size(), 0);
        for(int i = 0; i < puzzles.size(); i++) {
            int mask = 0;
            for(char ch: puzzles[i]) {
                int bit = ch - 'a';
                mask = mask | (1<<bit);
            }
            
            // start with first character
            vector<int> masks = mp[puzzles[i][0]-'a'];
            int cnt = 0;
            for(int tmp: masks) {
                if((mask & tmp) == tmp) cnt += 1;
            }
            ans[i] = cnt;
        }
        
        return ans;
    }
};

