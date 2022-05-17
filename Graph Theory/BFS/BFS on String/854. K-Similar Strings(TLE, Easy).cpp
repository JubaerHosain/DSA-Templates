class Solution {
private:
    int bfs(string &a, string &b) {
        unordered_set<string> used;
        queue<string> q;
        q.push(a);
        used.insert(a);
        
        int level = 0;
        while(!q.empty()) {
            level += 1;
            int qsize = q.size();
            // process all nodes at the same level
            while(qsize--) {
                string u = q.front();
                q.pop();
                
                // make all possible swap
                for(int i = 0; i < u.length(); i++) {
                    for(int j = i + 1; j < u.length(); j++) {
                        swap(u[i], u[j]);
                        if(!used.count(u)) {
                            if(u == b)
                                return level;
                            used.insert(u);
                            q.push(u);
                        }
                        // previous state
                        swap(u[i], u[j]);
                    }
                }
            }
        }
        
        return level;
    }
    
    
public:
    int kSimilarity(string s1, string s2) {
        if(s1 == s2)
            return 0;
        
        return bfs(s1, s2);
    }
};

