void getnxt() {
    nxt[0] = -1,nxt[1] = 0;
    int len = s.length();
    for(int i = 1,j = 0;i < len;i++) {
        while(j >= 0 && s[i] != s[j]) j = nxt[j];
        nxt[i+1] = ++j;
    }
}

for(int i = 0,j = 0;i < tlen;i++) {
    while(j >= 0 && t[i] != s[j]) j = nxt[j];
    if(++j == slen) cnt++;// t 中找到一个 s 
}
rep(i,2,n+1) {
	if(nxt[i] && (i) % (i-nxt[i]) == 0) 
 	// 长度为 i 的前缀的循环节大小为 i-nxt[i]
}
