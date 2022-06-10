#include<bits/stdc++.h>
using namespace std;

class SegmentTree2D {
private:
    int row, col;
    vector<vector<int>> grid;
    vector<vector<int>> tree;

    void build_y(int rootx, int leftx, int rightx, int rooty, int lefty, int righty) {
        if(lefty == righty) {
            if(leftx == rightx)
                tree[rootx][rooty] = grid[leftx][lefty];
            else 
                tree[rootx][rooty] = tree[2*rootx+1][rooty] + tree[2*rootx+2][rooty];
            return;
        }

        int mid = (lefty + righty) / 2;
        build_y(rootx, leftx, rightx, 2*rooty+1, lefty, mid);
        build_y(rootx, leftx, rightx, 2*rooty+2, mid+1, righty);

        // merge two child of rooty (update intermediate)
        tree[rootx][rooty] = tree[rootx][2*rooty+1] + tree[rootx][2*rooty+2];
    }

    void build_x(int rootx, int leftx, int rightx) {
        if(leftx == rightx) {
            build_y(rootx, leftx, rightx, 0, 0, col-1);
            return;
        }

        int mid = (leftx + rightx) / 2;
        build_x(2*rootx+1, leftx, mid);
        build_x(2*rootx+2, mid+1, rightx);

        // merge two child of rootx (update intermediate)
        build_y(rootx, leftx, rightx, 0, 0, col-1);
    }

    void build_tree() {
        // 0 indexing segment tree
        build_x(0, 0, row-1);
    }

    void update_y(int rootx, int leftx, int rightx, int rooty, int lefty, int righty, int x, int y, int value) {
        // update in leaf level
        if(lefty == righty) {
            if(leftx == rightx)
                tree[rootx][rooty] += value;
            else 
                tree[rootx][rooty] = tree[2*rootx+1][rooty] + tree[2*rootx+2][rooty];
            return;
        }

        int mid = (lefty + righty) / 2;
        if(y <= mid)
            update_y(rootx, leftx, rightx, 2*rooty+1, lefty, mid, x, y, value);
        else
            update_y(rootx, leftx, rightx, 2*rooty+2, mid+1, righty, x, y, value);

        // update intermediate nodes
        tree[rootx][rooty] = tree[rootx][2*rooty+1] + tree[rootx][2*rooty+2];
    }

    void update_x(int rootx, int leftx, int rightx, int x, int y, int value) {
        // update in leaf level
        if(leftx == rightx) {
            update_y(rootx, leftx, rightx, 0, 0, col-1, x, y, value);
            return;
        }

        int mid = (leftx + rightx) / 2;
        if(x <= mid)
            update_x(2*rootx+1, leftx, mid, x, y, value);
        else 
            update_x(2*rootx+2, mid+1, rightx, x, y, value);

        // update intermediate nodes
        update_y(rootx, leftx, rightx, 0, 0, col-1, x, y, value);
    }

    int query_y(int rootx, int rooty, int lefty, int righty,int y1, int y2) {
        // no overlap
        if(righty < y1 || lefty > y2)
            return 0;
        
        // total overlap
        if(y1 <= lefty && righty <= y2) 
            return tree[rootx][rooty];

        // partial overlap
        int mid = (lefty + righty) / 2;
        int left_sum = query_y(rootx, 2*rooty+1, lefty, mid, y1, y2);
        int right_sum = query_y(rootx, 2*rooty+2, mid+1, righty, y1, y2);

        return left_sum + right_sum;
    }

    int query_x(int rootx, int leftx, int rightx, int x1, int y1, int x2, int y2) {
        // no overlap
        if(rightx < x1 || leftx > x2)
            return 0;

        // total overlap
        if(x1 <= leftx && rightx <= x2) 
            return query_y(rootx, 0, 0, col-1, y1, y2);
        
        // partial overlap
        int mid = (leftx + rightx) / 2;
        int left_sum = query_x(2*rootx+1, leftx, mid, x1, y1, x2, y2);
        int right_sum = query_x(2*rootx+2, mid+1, rightx, x1, y1, x2, y2);

        return left_sum + right_sum;
    }

public:
    SegmentTree2D(vector<vector<int>> matrix) {
        row = matrix.size();
        col = matrix[0].size();
        grid = matrix;
        tree = vector<vector<int>> (4*row, vector<int>(4*col));

        // build segment tree
        build_tree();
    }

    void update(int x, int y, int value) {
        update_x(0, 0, row-1, x, y, value);
    }

    int get_sum(int x1, int y1, int x2, int y2) {
        return query_x(0, 0, row-1, x1, y1, x2, y2);
    }
};

int main(void) {
    freopen("input.txt", "r", stdin);
    
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    SegmentTree2D segmentTree(matrix);

    int q;
    cin >> q;

    while(q--) {
        char ch;
        cin >> ch;
        if(ch == 'q') {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << segmentTree.get_sum(x1-1, y1-1, x2-1, y2-1) << endl;
        } else {
            int x, y, value;
            cin >> x >> y >> value;
            segmentTree.update(x-1, y-1, value);
        }
    }

    return 0;
}