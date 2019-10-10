// 对于每条匹配边的两个端点有且只有一个在最小点覆盖的点集中；若存在一条边的一个端点一定不会被选，那另一个端点一定会在点集中
// 最大匹配数为 ans ，循环最多 ans ，每次更新一定会被选的点，对应匹配边的另一端点一定是不被选的点
// ans 次后，剩下的未被确定的匹配边可以任意全选 x 部或全选 y 部
// nou 是 X 部的点集大小， nov 是 Y 部的点集大小， n 是边集合大小， g[i] 存储第 i 条边的端点信息
// match[i] 存储 y 部 i 点的匹配点， _match[i] 存储 x 部的 i 点的匹配点
int ans = hungary(nou);
rep(i,0,nov) {
	if(match[i] != -1) {
		_match[match[i]] = i;
		stau[match[i]] = 1;
		stav[i] = 1;
	}
}
rep(z,0,ans) {
	rep(i,0,n) {
		int u = g[i].fi,v = g[i].se;
		if(!stau[u]) stau[match[v]] = 0;
		else if(!stav[v]) stav[_match[u]] = 0;
	}
}
rep(i,0,n) {
	int u = g[i].fi,v = g[i].se;
	if(stau[u]) ansu[u].pb(i+1);//点u覆盖的边集
	else ansv[v].pb(i+1);
}

//-----
//网络流跑最小割
//c[i] == 1,i是X部点;b[i]=1,i属于最小点覆盖
//建边时，x-y间的点流量限制是INF，S，T的边流量是1
 rep(i,1,n+1) {
	 if(c[i] ^ (dis[i] != -1)) b[i] = 1;
}
