#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

const int maxn = 20;

struct state {
	int time, pre, penalty;
}dp[1<<maxn];

int vis[1<<maxn];

struct homework {
	char name[101];
	int ddl, cost;
}h[maxn];

void print(int x) {
	if(dp[x].pre == -1) {
		return;
	}
	print(x^(1<<dp[x].pre));
//	std::cout << h[dp[x].pre].name << '\n';
	printf("%s\n",h[dp[x].pre].name);
}

int main(int argc, char *argv[]) {  
	int T;
//	std::cin >> T;
	scanf("%d",&T);
	while (T--) {
		int i,j,k,n,m,t;
//		std::cin >> n;
		scanf("%d",&n);
		for (i = 0; i < n; i++) {
//			 std::cin >> h[i].name >> h[i].ddl >> h[i].cost;	
			scanf("%s%d%d", h[i].name, &h[i].ddl, &h[i].cost);
		}
		m = (1<<n);
		dp[0].time = dp[0].penalty = 0;
		dp[0].pre = -1;
		memset(vis, 0, sizeof(vis));
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				k = (1<<j);
				if (i&k) {
					continue;
				}
				k = (k|i);
				if (!vis[k])  {
					vis[k] = 1;
					dp[k].pre = j;
					t = dp[i].penalty + h[j].cost - h[j].ddl;
					if (t <= 0) {
						dp[k].time = dp[i].time;
					} else {
						dp[k].time = dp[i].time + t;
					}
					dp[k].penalty = dp[i].penalty + h[j].cost;
				} else {
					t = dp[i].penalty + h[j].cost - h[j].ddl;
					t = (t<=0?dp[i].time:dp[i].time+t);
					if (t < dp[k].time) {
						dp[k].time = t;
						dp[k].penalty = dp[i].penalty + h[j].cost;
						dp[k].pre = j;
					}
				}
			}
		}
//		std::cout << dp[m-1].time << '\n';
		printf("%d\n",dp[m-1].time);
		print(m-1);
	}
	return 0;
}