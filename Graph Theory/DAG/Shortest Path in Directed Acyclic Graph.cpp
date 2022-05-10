using topological sorting, see gfg

Following is complete algorithm for finding shortest distances. 
1) Initialize dist[] = {INF, INF, ….} and dist[s] = 0 where s is the source vertex. 
2) Create a topological order of all vertices. 
3) Do following for every vertex u in topological order. 
………..Do following for every adjacent vertex v of u 
………………if (dist[v] > dist[u] + weight(u, v))  // dist[v] < dist[u] + weight(u, v) is for longest distance
………………………dist[v] = dist[u] + weight(u, v) 
