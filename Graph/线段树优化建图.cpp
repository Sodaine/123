/*
	建两个线段树A，B
	A中所有儿子节点向父亲节点连0边，B中所有父亲节点向儿子节点连0边
	B中所有点向A中所有对应点连0边
	A中所有叶子节点向B中所有叶子节点连0边（自己走向自己）
	对于输入的边[sl,sr] -> [tl,tr]
	A中[sl,sr]覆盖的点连向新建点p，p连向B中[tl,tr]覆盖到的点
*/
void ae(int u,int v,int w) {
	e[u].pb(mp(v,w));
}
void ae(int l,int r,int u,int w,int f,int n) {
	int t2 = 2*n-1;
	l += n-1,r += n-1;
	while(l <= r) {
		if(l & 1) (f==1?ae(l,u,w):ae(u,l+t2,w)),l++;
		if(~r & 1) (f==1?ae(r,u,w):ae(u,r+t2,w)),r--;
		l >>= 1,r >>= 1;
	}
}
int _;
void build(int n,int m) {
	int t2 = 2*n-1;
	rep(i,1,4*n+m) e[i].clear();
	rep(i,1,n) {
		ae(i<<1,i,0);
		ae(i<<1|1,i,0);
		ae(i+t2,(i<<1)+t2,0);
		ae(i+t2,(i<<1|1)+t2,0);
	}
	rep(i,1,2*n) ae(i+t2,i,0);
	rep(i,1,n+1) ae(i+n-1,i+n-1+t2,0);
	_ = 4*n-1;
}
void addEdge(int sl,int sr,int tl,int tr,int w,int n) {
	ae(sl,sr,_,w,1,n);
	ae(tl,tr,_,0,-1,n);
	_++;
}
