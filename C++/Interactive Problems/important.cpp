// structure of two function...modify it according to problem.

int query(int y) {
    int node;
    cout << '? ' << y;
    fflush(stdout);
    cin >> node;
    return node;
}

void print(int x) {
    cout << '! ' << x << endl;
    fflush(stdout);
}
