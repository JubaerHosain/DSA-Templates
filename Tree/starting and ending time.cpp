Initially, T equals zero. Now we have a beautiful structure giving us so much information about the tree. 
Consider all segments [tinv;toutv]. We can see that is no pair of intersecting segments. 
The pair of segments [tinv;toutv] and [tinu;toutu] is either non-intersecting at all or one segment lies inside the other one.
The second beautiful fact is that for each vertex u in the subtree of v the segment [tinu;toutu] lies inside the segment [tinv;toutv].
  
So, we can check if one vertex is the parent of the other: the vertex v is the parent of the vertex u if and only if tinv≤tinu and toutu≤toutv 
(the vertex is the parent of itself).
How do we check if the vertex u lies on the path from the root to the vertex fv? 
It lies on this path if the root is the parent of u (it is always true) and u is the parent of fv. 
This approach can be used for each vertical path (such a path from x to y that lca(x,y) is either x or y).
