//Low-link value of a node copletely depend on dfs order
//The nodes same low-link value may or may not belong same scc
//Tarjan's Algo defines a criteria while update low-link value
//During a dfs, Tarjan's Algo keep track of active nodes
//A node u can use a node v to minimize it's low-link value if and only if node v is in active node list
//If in_time is equal to it's low-link value then it is the root of a scc and we found a scc.

