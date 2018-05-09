#include <iostream>
#include <algorithm>
#include <cstring>

const int inf = 0x3f3f3f3f;
const int maxn=10005;

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while (T--) {
		int e, f;
		std::cin >> e >> f;
		int V = f-e;
		int n;
		std::cin >> n;
		int v[maxn], c[maxn], dp[maxn];
		for (int i = 1; i <= n; i++) {
			std::cin >> v[i] >> c[i];
		}
		memset(dp, 0x3f, sizeof(dp));
		dp[0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = c[i]; j <= V; j++) {
				dp[j] = std::min(dp[j - c[i]] + v[i], dp[j]);
			}
		}
		if (dp[V] == inf) {
			std::cout << "This is impossible.\n";
		} else {
			std::cout << "The minimum amount of money in the piggy-bank is "<< dp[V] << ".\n";
		}
	}
}