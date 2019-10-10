int vis[N],id[N];
vi e[N],g[N],order;
//e[u].pb(v),g[v].pb(u):e 为原图， g 为逆图
void topo(int u) {
	vis[u] = 1;
	for(int v:g[u]) if(!vis[v]) topo(v);
	order.pb(u);
}
void scc(int u,int c) {
	vis[u] = 0,id[u] = c;
	for(int v:e[u]) if(vis[v]) scc(v,c);
}
void solve(int n)
{
	memset(vis,0,sizeof(vis[0])*n);
	rep(i,0,n) if(!vis[i]) topo(i);
	reverse(order.begin(),order.end());
  	int _=0;
  	for(int u:order) if(vis[u]) scc(u,_++);
}
