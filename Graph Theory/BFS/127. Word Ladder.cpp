class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> words;
        bool hasEnd = false;
        for(string word: wordList) {
            words.insert(word);
            if(word == endWord)
                hasEnd = true;
        }
        
        if(!hasEnd)
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        int depth = 0;
        while(!q.empty()) {
            depth += 1;
            int qsize = q.size();
            // traverse all nodes of current level
            // bcz we are not going to use depth array
            while(qsize--) {
                string curr = q.front();
                q.pop();
                for(int i = 0; i < curr.length(); i++) {
                    string tmp = curr;
                    // changing char at i, check all posibilities
                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        tmp[i] = ch;
                        if(tmp == curr) 
                            continue;
                        else if(tmp == endWord) 
                            return depth + 1;
                        else if(words.count(tmp) ) {
                            q.push(tmp);
                            words.erase(tmp);
                        }
                    }
                }
            }
        }
        
        // 26 * (length^2) * N
        
        return 0;
    }
};

