class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<pair<int, int>> points;
        
        for(int i = 0; i < n; i++) {
            int x1 = buildings[i][0];
            int x2 = buildings[i][1];
            int y = buildings[i][2];
            // start point of each block represented as -y
            points.push_back({x1, -y}); 
            points.push_back({x2, y});
        }
        
        sort(points.begin(), points.end());
        
        multiset<int> heap;
        heap.insert(0);
        
        int prev = 0;
        vector<vector<int>> ans;
        for(auto &it: points) {
            int x = it.first;
            int y = it.second;
            if(y < 0) 
                heap.insert(-y);
            else
                heap.erase(heap.find(y));
            // heap.erase(y) removes all occurances of y
            
            if(prev != *heap.rbegin()) {
                y = *heap.rbegin();
                ans.push_back({x, y});
                prev = y;
            }
        }
        
        return ans;
    }
};


