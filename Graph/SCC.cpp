int vis[N],id[N];
vi e[N],g[N],order;
void topo(int u) {
	vis[u] = 1;
	for(int v:g[u]) {
		if(!vis[v]) topo(v);
	}
	order.pb(u);
}
void scc(int u,int c) {
	vis[u] = 0,id[u] = c;
	if(mn > w[u]) mn = w[u],cnt = 1;
	else if(mn == w[u]) cnt++;
	for(int v:e[u]) {
		if(vis[v]) scc(v);
	}
}
void solve()
{
  int _=0;
  for(int u:order) {
		if(vis[u]) {
			scc(u,_++);
		}
	}
}
