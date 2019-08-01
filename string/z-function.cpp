/*
z[i] : max length of string start from i which is also prefix of s
*/
int z[N];
string s;
void zfunction() {
	int len = s.length();
	z[0] = len;
	for(int i = 1,L = 0,R = 0;i < len;i++) {
		if(R >= i) z[i] = min(R - i + 1,z[i - L]);
		else z[i] = 0;
		while(i + z[i] < len && s[z[i]] == s[i + z[i]]) ++z[i];
		if(i + z[i] - 1 > R) R = i + z[i] - 1,L = i;
	}
}
