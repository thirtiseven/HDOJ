#include <iostream>
#include <cstring>
#include <queue>

const int maxn = 212;

int n, m;		
int g[maxn][maxn];	//0-labeled
int linker[maxn];
bool used[maxn];

bool dfs(int u) {
	int v;
	for(v = 0; v < n; v++) {
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
	for(u = 0; u < n; u++) {
		memset(used, 0, sizeof(used));
		if(dfs(u)) {
			res++;
		}
	} 
	return res;   
}   

int clour[maxn];

int bfs(){    
	int j;	
	memset(clour,-1,sizeof(clour));
	for(int j=0;j<n;j++) {	
		if(clour[j]!=-1) continue;	
		std::queue<int> q;	
		clour[j]=1;    
		q.push(j);	
		while(!q.empty()) {		
			int k=q.front();
			q.pop();		
			for(int i=0;i<n;i++) {			
				if(g[k][i]&&clour[i]==clour[k]) {		    	
					return 0;			
				}			
				if(g[k][i]&&clour[i]==-1)	 {				
					q.push(i);				
					clour[i]=1-clour[k];			
				}		
			}	
		}	
	}	
	return 1;
}


int main(int argc, char *argv[]) {  
	int u, v;
	while (std::cin >> n >> m) {
		memset(g, 0, sizeof(g));
		for (int i = 0; i < m; i++) {
			std::cin >> u >> v;
			g[u-1][v-1] = 1;
			g[v-1][u-1] = 1;
		}
		memset(clour, 0, sizeof(clour));
		bool yes = 1;
		for (int i = 0; i < n; i++) {
			if (!clour[i]) {
				if (!bfs()) {
					yes = 0;
					break;
				}
			}
		}
		if (!yes) {
			std::cout << "No\n";
		} else {
			std::cout << hungary()/2 << '\n';
		}
	}
}