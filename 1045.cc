#include <iostream>
#include <string>
#include <cstring>

const int maxn = 5;

std::string s[maxn];
int x[maxn][maxn], y[maxn][maxn];
int g[maxn*maxn][maxn*maxn];

int p;		
int linker[maxn*maxn];
bool used[maxn*maxn];

bool dfs(int u) {
	int v;
	for(v = 0; v < p; v++) {
		if(g[u][v] && !used[v]) {
			used[v] = true;
			if(linker[v] == -1 || dfs(linker[v])) {
				linker[v] = u;
				return true;
			}    
		} 
	}
	return false;  
}   
 
int hungary() {
	int res = 0;
	int u;
	memset(linker, -1, sizeof(linker)); 
	for(u = 0; u < p; u++) {
		memset(used, 0, sizeof(used));
		if(dfs(u)) {
			res++;
		}
	} 
	return res;   
}   


int main(int argc, char *argv[]) {  
	int n;
	while (std::cin >> n) {
		if (n == 0) {
			exit(0);
		}
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		memset(g, 0, sizeof(g));
		for (int i = 0; i < n; i++) {
			std::cin >> s[i];
		}
		int cnt = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (s[i][j] == '.') {
					x[i][j] = cnt;
					if (j == n-1 || s[i][j+1] != '.') {
						cnt++;
					}
				}
			}
		}
		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++) {
				if (s[i][j] == '.') {
					y[i][j] = cnt;
					if (i == n-1 || s[i+1][j] != '.') {
						cnt++;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (s[i][j] == '.') {
					g[x[i][j]][y[i][j]] = 1;
				}
			}
		}
		p = cnt;
		std::cout << hungary() << '\n';
	} 
}