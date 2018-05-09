#include <iostream>
#include <algorithm>
#include <cstring>

using ll = long long int;
const ll maxn = 1000000;
const ll inf = 0x7fffffff;

ll s[maxn], maxx[maxn], dp[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int m, n;
	ll mmax;
	while (std::cin >> m >> n) {
		for (int i = 1; i <= n; i++) {
			std::cin >> s[i];
		}
		memset(dp, 0, sizeof(dp));
		memset(maxx, 0, sizeof(maxx));
		for (int i=1; i <= m; i++) {
			mmax = -inf;
			for (int j = i; j <= n; j++) {
				dp[j] = std::max(dp[j-1]+s[j], maxx[j-1] + s[j]);
				maxx[j-1] = mmax;
				mmax = std::max(mmax,dp[j]);
			}
		}
		std::cout << mmax << '\n';
	}
}