struct NODE{
	int ch[26];
	int len,fa;//fa:最长的存在的后缀的结点编号
	void clear() {
		memset(ch,0,sizeof(ch));len = 0;
	}
}dian[N<<1];
int last,tot;
void init(){
	last = 1;tot = 1;
	dian[1].clear();
}
void add(int c) {
	int p = last;int np = last = ++tot;
	dian[np].clear();
	dian[np].len = dian[p].len+1;
	for(;p&&!dian[p].ch[c];p = dian[p].fa) dian[p].ch[c] = np;
	if(!p) dian[np].fa = 1;
	else {
		int q = dian[p].ch[c];
		if(dian[q].len == dian[p].len+1) dian[np].fa = q;
		else {
			int nq = ++tot;dian[nq].clear();
			dian[nq] = dian[q];
			dian[nq].len = dian[p].len+1;
			dian[q].fa = dian[np].fa = nq;
			for(;p&&dian[p].ch[c] == q;p = dian[p].fa) dian[p].ch[c] = nq;
		}
	}
}
//id[i]：按len排序后，排在第i位的结点编号
int cnt[N<<1],id[N<<1];
void bucketsort() {
	memset(cnt,0,sizeof(cnt));
	rep(i,1,tot+1) ++cnt[dian[i].len];
	rep(i,1,tot+1) cnt[i] += cnt[i-1];
	rep(i,1,tot+1) id[cnt[dian[i].len]--] = i;
}
void topogao() {
	bucketsort();
	rep(i,1,tot+1) {
		int u = id[i],fa = dian[u].fa;
		...;
	}
}
void run(char *t) {
	int u = 1,len = 0;
	for(int i = 0;t[i];i++) {
		int c = t[i] - 'a';
		while(u && !dian[u].ch[c]) u = dian[u].fa,len = dian[u].len;
		if(u) {
			u = dian[u].ch[c];
			len++;
		}else u = 1,len = 0;
		mx[u] = max(len,mx[u]);
	}
}
