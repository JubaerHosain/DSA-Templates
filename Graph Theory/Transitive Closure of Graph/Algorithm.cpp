// reach is a boolean array
// using k as a intermediate state
for (k = 0; k < V; k++) {
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            reach[i][j] = (reach[i][j]) || (reach[i][k] && reach[k][j]) ? 1 : 0;
        }
    }
}
 