	//sa[0:n] : the index of the suffix which is rank i
	//sa[0] = n,the empty string consist only 0
	//h[1:n+1] : the length of the longest common prefix of S[sa[i-1]] and S[sa[i]]
	//h[1] == h[n+1] == 0
	//rk[0:n] : the rank of the suffix from i
	//rk[n] = 0;
	int t[N],wa[N],wb[N],sa[N],h[N];
	void sort(int *x,int *y,int n,int m) {
		rep(i,0,m) t[i] = 0;
		rep(i,0,n) t[x[y[i]]]++;
		rep(i,1,m) t[i] += t[i-1];
		per(i,0,n) sa[--t[x[y[i]]]] = y[i];
	}
	bool cmp(int *x,int a,int b,int d) {
		return x[a] == x[b] && x[a+d] == x[b+d];
	}
	void da(int *s,int n,int m) {
		int *x = wa,*y = wb;
		rep(i,0,n) x[i] = s[i],y[i] = i;
		sort(x,y,n,m);
		for(int j=1,p=1;p<n;m=p,j<<=1) {
			p = 0;rep(i,n-j,n) y[p++] = i;
			rep(i,0,n) if(sa[i] >= j) y[p++] = sa[i] - j;
			sort(x,y,n,m);
			swap(x,y);p = 1;x[sa[0]] = 0;
			rep(i,1,n) x[sa[i]] = cmp(y,sa[i],sa[i-1],j)?p-1:p++;
		}
	}
	void cal_h(int *s,int n,int *rk) {
		int j,k = 0;
		//from i=0,then rk[n] = 0;
		for(int i=0;i<=n;++i) rk[sa[i]] = i;
		for(int i=0;i<n;h[rk[i++]] = k)
			for(k&&--k,j=sa[rk[i]-1];s[i+k]==s[j+k];++k);
		h[n+1] = 0;
	}

struct DA{
	int p[18][N],rk[N],in[N],Log[N],n;
	void init(string s) {
		n = s.length();
		rep(i,0,n) in[i] = s[i] - 'a' + 1;
		in[n] = 0;
	}
	void Build() {
		in[n] = 0;
		da(in,n+1,300);//[1,300] is the set of in[]
		cal_h(in,n,rk);
		Log[0] = -1;for(int i=1;i<=n;++i) Log[i] = Log[i-1] + (i==(i&(-i)));
		for(int i=1;i<=n;++i) p[0][i] = h[i];
		for(int j=1;1<<j<=n;++j) {
			int lim = n+1-(1<<j);
			for(int i=1;i<=lim;++i)
				p[j][i] = min(p[j-1][i],p[j-1][i+(1<<j>>1)]);
		}
	}
	//the length of the longest common prefix of S[a] and S[b]
	//!! 0<=a,b<=n
	int lcp(int a,int b) {
		if(a == b) return n - a;
		a = rk[a],b = rk[b];
		if(a > b) swap(a,b);++a;
		int t = Log[b-a+1];
		return min(p[t][a],p[t][b-(1<<t)+1]);
	}
	void show() {
		rep(i,1,n+1) {
			rep(j,sa[i],n+1) cout<<in[j]<<' ';cout<<endl;
		}
	}
}Da;
