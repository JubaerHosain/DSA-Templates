int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool valid(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < m);
}
