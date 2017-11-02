#include <iostream>
#include <cstring>
#include <set>

#define N 1010

int fa[N];
std::set<int> aa;

void init(int n) {
	for (int i = 1; i <= n; i++) fa[i] = i;
}

int find(int u) {
	return fa[u] == u ? fa[u] : fa[u] = find(fa[u]);
}

void unin(int u, int v) {
	fa[find(v)] = find(u);
}

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	while(T--) {
		int m, n, alice, bob;
		memset(fa, 0, sizeof(fa));
		aa.clear();
		std::cin >> m >> n;
		init(m);
		for(int i = 0; i < n; i++) {
			std::cin >> alice >> bob;
			unin(alice, bob);
		}
		for(int i = 1; i <= m; i++) {
			aa.insert(find(i));
		}
		std::cout << aa.size() << '\n';
	}
	return 0;
}