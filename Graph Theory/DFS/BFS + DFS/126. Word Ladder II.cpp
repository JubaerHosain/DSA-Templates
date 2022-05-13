class Solution {
private:
    void dfs(string &start, string &end, map<string, vector<string>> &adj, vector<string> &path, vector<vector<string>> &ans) {
        path.push_back(start);
        if(start == end) {
            ans.push_back(path);
            return;
        }
        for(string curr: adj[start]) {
            dfs(curr, end, adj, path, ans);
            path.pop_back();   // this is backtracking
        }
    }
    
    
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // a special adj 
        map<string, vector<string>> adj;
        map<string, int> level;
        set<string> words(wordList.begin(), wordList.end());
        
        vector<vector<string>> ans;
        
        if(words.count(endWord) == 0)
            return ans;
        
        // bfs
        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 0;
        while(!q.empty()) {
            string curr = q.front();
            q.pop();
            string tmp = curr;
            // changing char at i, check all posibilities
            for(int i = 0; i < curr.length(); i++) {
                for(int c = 'a'; c <= 'z'; c++) {
                    tmp[i] = c;
                    if(tmp[i] == curr[i] || words.count(tmp) == 0)
                        continue;
                    else if(level.count(tmp) == 0) {
                        level[tmp] = 1 + level[curr];
                        adj[curr].push_back(tmp);
                        q.push(tmp);
                    } else if(level[tmp] == 1 + level[curr]) {
                        adj[curr].push_back(tmp);
                    }
                }
                // restore char at i
                tmp[i] = curr[i];
            }
        }
        
        vector<string> path;
        dfs(beginWord, endWord, adj, path, ans);
        
        return ans;
    }
};



