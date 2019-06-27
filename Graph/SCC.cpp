int vis[N],id[N];
vi e[N],g[N],order;
//e[u].pb(v),g[v].pb(u):e为原图，g为逆图
void topo(int u) {
	vis[u] = 1;
	for(int v:g[u]) {
		if(!vis[v]) topo(v);
	}
	order.pb(u);
}
void scc(int u,int c) {
	vis[u] = 0,id[u] = c;
	for(int v:e[u]) {
		if(vis[v]) scc(v);
	}
}
void solve()
{
  	int _=0;
  	for(int u:order) {
		if(vis[u]) scc(u,_++);
	}
}
