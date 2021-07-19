//This is coppied code
//i should code in my own way
//littlbe change in build function (previous implementation i used return but in this problem void is better)
//check other functions also


//{odd, even}
const int maxN = 100001;
pair<int,int> st[4*maxN];
int val[maxN];
 
void build(int si , int ss , int se)
{
	if(ss == se)
	{
		if(val[ss] % 2 == 1)
		st[si] = {1 , 0};
		else
		st[si] = {0 , 1};
		
		return;
	}
	
	int mid = (ss + se) / 2;
	build(2*si , ss , mid);
	build(2*si+1, mid+1 , se);
	
  //previous implementation is used return
	st[si].first = st[2*si].ff + st[2*si+1].ff;
	st[si].second = st[2*si].ss + st[2*si+1].ss;
}
 
void update(int si , int ss , int se , int qi , int newVal)
{
	if(ss == se)   //update in leaf
	{ 
		if(val[ss] % 2)
		st[si] = {0 , 1};
		else
		st[si] = {1 , 0};
		
		val[ss] = newVal;
		return;
	}
	
	int mid = (ss + se) / 2;
	if(qi <= mid) update(2*si , ss , mid , qi , newVal);
	else		  update(2*si+1 , mid+1 , se , qi , newVal);
	
	st[si].first = st[2*si].ff + st[2*si+1].ff; //update in intermediate nodes
	st[si].second = st[2*si].ss + st[2*si+1].ss;
}
 
int getEven(int si , int ss , int se , int qs , int qe)
{
	if(ss > qe || se < qs) return 0;
	
	if(ss >= qs && se <= qe)
	return st[si].ss;
	
	int mid = (ss + se) / 2;
	
	int l = getEven(2*si , ss , mid , qs , qe);
	int r = getEven(2*si+1 , mid+1 , se , qs , qe);
	
	return l+r;
}
 
int getOdd(int si , int ss , int se , int qs , int qe)
{
	if(ss > qe || se < qs) return 0;
	
	if(ss >= qs && se <= qe)
	return st[si].ff;
	
	int mid = (ss + se) / 2;
	
	int l = getOdd(2*si , ss , mid , qs , qe);
	int r = getOdd(2*si+1 , mid+1 , se , qs , qe);
	
	return l+r;
}
