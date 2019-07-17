void dfs(int u,int fh) {
	/* L[u] is the left boundary of the rectangle with height h[u]*/
	/* same as R[u]*/
	L[u] = u,R[u] = u;
	if(l[u]) dfs(l[u],h[u]),L[u] = L[l[u]];
	if(r[u]) dfs(r[u],h[u]),R[u] = R[r[u]];
	/* x,y is the edge length of control region of u*/
	int y = h[u] - fh,x = R[u] - L[u] + 1;

}
stack<int> stk;
void solve()
{
	rep(i,1,n+1) scanf("%d",&h[i]);
	int mn = INF,x;
	rep(i,1,n+1) {
		mn = min(mn,h[i]);
		x = 0;
		while(!stk.empty() && h[stk.top()] > h[i]) {
			r[stk.top()] = x;
			x = stk.top();
			stk.pop();
		}
		l[i] = x;//if the son of i is empty,it will be 0
		stk.push(i);
	}
	for(x = 0;!stk.empty();x = stk.top(),stk.pop())
		r[stk.top()] = x;
	rep(i,1,n+1) {
		if(h[i] == mn) {
			dfs(i,0);//i is the root
			break;
		}
	}
}
