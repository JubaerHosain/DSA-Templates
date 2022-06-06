// input has at least one valid answer

class Solution {
private:
    vector<string> path;
    map<string, int> out_degree;
    map<string, vector<string>> graph;
    
    void make_path(string u) {
        while(out_degree[u] > 0) {
            string v = graph[u].back();
            graph[u].pop_back();
            out_degree[u] -= 1;
            make_path(v);
        }
        path.push_back(u);
    }
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &it: tickets) {
            graph[it[0]].push_back(it[1]);
            out_degree[it[0]] += 1;
        }
        
        for(auto &it: graph) 
            sort(it.second.begin(), it.second.end(), greater<string>());
        
        string src = "JFK";
        make_path(src);
        
        reverse(path.rbegin(), path.rend());
        
        return path;
    }
};

