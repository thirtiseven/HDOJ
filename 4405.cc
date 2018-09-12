#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

const int maxn = 100009;

std::vector<int> g[maxn];
double dp[maxn];
bool vis[maxn];
int m, n, u, v;

void inti() {
	for (int i = 0; i <= n; i++) {
		g[i].clear();
	}
	std::fill(dp, dp+maxn, 0);
	for (int i = 0; i < m; i++) {
		std::cin >> u >> v;
		g[v].push_back(u);
	}
	std::fill(vis, vis+maxn, 0);
}

int main(int argc, char *argv[]) {  
	while (std::cin >> n >> m) {
		if (!m && !n) {
			break;
		}
		inti();
		for (auto it: g[n]) {
			vis[it] = 1;
			dp[it] = 0;
		}
		for (int i = n-1; i >= 0; i--) {
			if (!vis[i]) {
				vis[i] = 1;
				for (int j = i+1; j <= i+6; j++) {
					dp[i] += dp[j]/6.0;
				}
				dp[i] += 1.0;
			}
			for (auto it: g[i]) {
				dp[it] = dp[i];
				vis[it] = 1;
			}
		}
		std::cout << std::fixed << std::setprecision(4) << dp[0] << std::endl;
	}
}