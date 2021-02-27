
/*************Disjoint Set*************/
vector<int> parent(N, -1);

int find(int key){
    if(parent[key] == -1)
        return key;     
    return find(parent[key]);
}
        
void merge(int x, int y){
    int xset = find(x);
    int yset = find(y);  
    parent[yset] = xset;
}
