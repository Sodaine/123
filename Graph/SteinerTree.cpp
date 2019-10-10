/* 有别于一般的最小生成树，图中可以添加不必须的辅助点，用以使得图联通的代价降低

  dp(sta,s) 表示必须点的联通状态是 sta ，并且图中有根为 s ，两个转移步骤
  + dp(sta,s) = min(dp(s1,s)+dp(sta-s1,s)); (s1|sta = sta)
  + dp(sta,s) = min(dp[sta,s'] + w[s',s])
    其中第二步转移可以用最短路算法进行优化，将第二位状态作为点的标号
*/
vector<pii> e[N];
//n < N,k <= M
int n,k,dp[N][1<<M],in[N];
queue<int> Q;
void spfa(int msk) {
	while(!Q.empty()) {
		int u = Q.front();Q.pop();
		in[u] = 0;
		rep(i,0,sz(e[u])) {
			int v = e[u][i].fi,w = e[u][i].se;
			if(dp[v][msk] > dp[u][msk] + w) {
				dp[v][msk] = dp[u][msk] + w;
				if(!in[v]) Q.push(v),in[v] = 1;
			}
		}
	}
}
int solve()
{
	memset(dp,0x3f,sizeof(dp));
	rep(i,0,k) dp[i][1<<i] = 0;
	rep(msk,1,1<<k) {
		for(int s1=msk;s1;s1 = (s1-1) & msk) rep(s,k,n) {
			dp[s][msk] = min(dp[s][msk],dp[s][s1] + dp[s][msk^s1]);
		}
		rep(s,0,n) if(dp[s][msk] < INF) Q.push(s),in[s] = 1;
		spfa(msk);
	}
	int ans = INF;
	rep(i,k,n) ans = min(ans,dp[i][(1<<k)-1]);
	return ans;
}
