class Solution {
private: 
    int get_score(string &str, vector<int> &freq, vector<int> &score) {
        int score_cnt = 0;
        for(char c: str) {
            if(freq[c-'a'] <= 0)
                return INT_MIN;
            score_cnt += score[c-'a'];
            freq[c-'a'] -= 1;
        }
        return score_cnt;
    }
    
    int possible(vector<string> &words, vector<int> freq, vector<int> &score, int num) {
        int score_cnt = 0;
        int n = words.size();
        for(int i = 0; i < n; i++) {
            if(num & (1<<i)) {
                int tmp = get_score(words[i], freq, score);
                if(tmp == INT_MIN) return tmp;
                score_cnt += tmp;
            }
        }
        return score_cnt;
    }
    
    
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int N = words.size();
        vector<int> freq(26, 0);
        for(int i = 0; i < letters.size(); i++) 
            freq[letters[i]-'a'] += 1;
        
        int ans = INT_MIN;
        for(int num = 0; num < pow(2, N); num++) {
            int tmp = possible(words, freq, score, num);
            ans = max(ans, tmp);
        }
        
        return ans;
    }
};