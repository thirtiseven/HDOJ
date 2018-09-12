#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

const int maxn = 521;
std::vector<int> g[maxn];
int du[maxn], n, m, l[maxn];
bool flag = 1;

bool topsort() {
	std::fill(du, du+maxn, 0);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < g[i].size(); j++) {
			du[g[i][j]]++;
		}
	}
	int tot = 0;
	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
	for(int i = 0; i < n; i++) {
		if(!du[i]) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		int x = q.top();
		q.pop();
		l[tot++] = x;
		for(int j = 0; j < g[x].size(); j++) {
			int t = g[x][j];
			du[t]--;
			if(!du[t]) {
				q.push(t);
			}
		}
	}
	if(tot == n) {
		return 1;
	}
	return 0;
}

int main(int argc, char *argv[]) {  
	int x, y;
	while (std::cin >> n >> m) {
		for (int i = 0; i < maxn; i++) {
			g[i].clear();
		}
		for (int i = 0; i < m; i++) {
			std::cin >> x >> y;
			g[x-1].push_back(y-1);
		}
		topsort();
		for (int i = 0; i < n-1; i++) {
			std::cout << l[i]+1 << " ";
		}
		std::cout << l[n-1]+1 << '\n';
	}
}