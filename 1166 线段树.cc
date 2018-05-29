#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
//A为原始数组，sum记录区间和，Add为懒惰标记

const int maxn = 50009;
using ll = long long;

ll T[maxn*4];
int M,n;
void build()
{
	for(M=1;M<=n+1;M<<=1);
	for(int i=1;i<=n;i++)
		std::cin >> T[i+M];
	for(int i=M-1;i;i--)
		T[i]=T[i<<1]+T[i<<1|1];
}

void update(int x,int val)
{
	T[x+=M]+=val;
	for(x>>=1;x>=1;x>>=1)
	{
		T[x]=T[x<<1]+T[x<<1|1];
	}
}

ll query(int l,int r)
{
	l=l+M-1,r=r+M+1;
	ll ans=0;
	for(;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1)ans+=T[l^1];
		if(r&1) ans+=T[r^1];
	}
	return ans;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	std::cin >> T;
	for (int CAS = 1; CAS <= T; CAS++) {
		std::cin >> n;
		build();
		std::cout << "Case " << CAS << ":\n";
		std::string s;
		while(std::cin >> s) {
			if (s[0] == 'E') {
				break;
			} else if (s[0] == 'A') {
				int a, b;
				std::cin >> a >> b;
				update(a, b);
			} else if (s[0] == 'S') {
				int a, b;
				std::cin >> a >> b;
				update(a, -b);
			} else if (s[0] == 'Q') {
				int a, b;
				std::cin >> a >> b;
				std::cout << query(a, b) << '\n';
			}
		}
	}
}