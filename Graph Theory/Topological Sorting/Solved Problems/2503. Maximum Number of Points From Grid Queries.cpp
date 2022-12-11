class Solution {
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    bool valid(int i, int j, int m, int n) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size();
        int n = grid[0].size();

        //{val, x, y}
        set<pair<int, pair<int, int>>> minh;
        vector<vector<bool>> used(m, vector<bool>(n));
        minh.insert({grid[0][0], {0, 0}});

        vector<int> order;
        while(minh.size() > 0) {
            auto it = minh.begin();
            int i = it->second.first, j = it->second.second;
            order.push_back(it->first);
            used[i][j] = true;
            minh.erase(it);
            for(int k = 0; k < 4; k++) {
                int x = dir[k][0] + i;
                int y = dir[k][1] + j;
                if(valid(x, y, m, n) && !used[x][y] && !minh.count({grid[x][y], {x, y}})) 
                    minh.insert({grid[x][y], {x, y}});
            }
        }

        assert(order.size() == m*n);

        for(int i = 1; i < order.size(); i++) {
            if(order[i] < order[i-1])
                order[i] = order[i-1];
        }

        vector<int> ans;
        for(int val: queries) {
            int pos = lower_bound(order.begin(), order.end(), val) - order.begin();
            ans.push_back(pos);
        }

        return ans;
    }
};




