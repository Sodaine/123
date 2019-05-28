 //对于每条匹配边的两个端点有且只有一个在最小点覆盖的点集中；若存在一条边的一个端点一定不会被选，那另一个端点一定会在点集中
 //最大匹配数为ans，循环最多ans，每次更新一定会被选的点，对应匹配边的另一端点一定是不被选的点
 //ans次后，剩下的未被确定的匹配边可以任意全选x部或全选y部
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
			if(!stau[u]) {
				stav[v] = 2;
				stau[match[v]] = 0;
			}else if(!stav[v]) {
				stau[u] = 2;
				stav[_match[u]] = 0;
			}
		}
	}
	rep(i,0,n) {
		int u = g[i].fi,v = g[i].se;
		if(stau[u]) {
			ansu[u].pb(i+1);
		}else ansv[v].pb(i+1);
	}
