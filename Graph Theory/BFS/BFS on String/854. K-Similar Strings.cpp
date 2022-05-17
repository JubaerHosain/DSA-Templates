class Solution {
private:
    int bfs(string &a, string &b) {
        set<string> used;
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
                
                // escape previously matched characters
                int i = 0;
                while(i < u.length() && u[i] == b[i])
                    i += 1;
                
                // make only possible swap to make i th char same
                // should not check all possibilities using two for loop(gives tle)
                for(int j = i + 1; j < u.length(); j++) {
                    if(b[i] == u[j]) {
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