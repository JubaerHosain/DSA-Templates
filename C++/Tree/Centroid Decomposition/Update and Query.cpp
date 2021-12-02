//dist(a , b) : returns the distance between node in LogN using LCA
//we are assuming parent of root of centroid tree is -1
 
void update(int node)
{
	int curr = node;
	while(curr != -1)
	{
		res[curr] = min(res[curr] , dist(curr , node));
 
		curr = par[curr];
	}
}
 
int query(int node)
{
	int curr = node;
	int ans = INF;
	while(curr != -1)
	{
		ans = min(ans , res[curr] + dist(node , curr));
		curr = par[curr];
	}
 
	return ans;
}
