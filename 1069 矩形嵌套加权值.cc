#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

struct cube {
	int a, b, c;
	cube(int x, int y, int z) {
		a = x, b = y, c = z;
	}
};

std::vector<cube> tow;

bool cmp(cube alice, cube bob) {
	if (alice.a == bob.a) {
		return alice.b > bob.b;
	}
	return alice.a > bob.a;
}

int main(int argc, char *argv[]) {  
	int n;
	int x, y, z;
	int CAS = 1;
	while(std::cin >> n) {
		if (!n) break;
		tow.clear();
		for (int i = 0; i < n; i++) {
			std::cin >> x >> y >> z;
			tow.push_back(cube(std::max(x, y), std::min(x, y), z));
			tow.push_back(cube(std::max(x, z), std::min(x, z), y));
			tow.push_back(cube(std::max(z, y), std::min(z, y), x));
		}
		std::sort(tow.begin(), tow.end(), cmp);
		int dp[123];
		memset(dp, 0, sizeof(dp));
		int ans = dp[0] = tow[0].c;
		for (int i = 1; i < tow.size(); i++) {
			dp[i] = tow[i].c;
			int maxx = 0;
			for (int j = 0; j < i; j++) {
				if (tow[i].a < tow[j].a && tow[i].b < tow[j].b) {
					maxx = std::max(maxx, dp[j]);
				}
			}
			dp[i] += maxx;
			ans = std::max(ans, dp[i]);
		}
		std::cout << "Case " << CAS << ": maximum height = " << ans << '\n';
		CAS++;
	} 
}