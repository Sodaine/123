struct NODE{
	int ch[26];
	int len,fa;
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
