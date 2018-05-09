#include <iostream>
#include <algorithm>
#include <cstring>

int main(int argc, char *argv[]) {  
	int n;
	while (std::cin >> n) {
		if (n == 0) break;
		int a[1234], dp[1234];
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) {
			int ans = 0;
			for (int j = 0; j < i; j++) {
				if (a[j] < a[i]) {
					ans = std::max(dp[j], ans);
				}
			}
			dp[i] = a[i] + ans;
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			res = std::max(res, dp[i]);
		}
		std::cout << res << '\n';
	}
}