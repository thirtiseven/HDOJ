#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#define maxt 75

struct coin {
	int num;
	double probability;
};

int main(int argc, char *argv[]) {  
	int cas;
	int k;
	std::cin >> cas;
	while(cas--) {
		std::cin >> k;
		coin lucky[12];
		for(int i = 0; i < k; i++) {
			std::cin >> lucky[i].num >> lucky[i].probability;
		}
		double ans[12];
		double die[maxt][12];
		memset(die, 0, sizeof(die));
		memset(ans, 0, sizeof(ans));
		for(int i = 1; i <= maxt; i++) {
			for(int j = 0; j < k; j++) {
				die[i][j] = pow(1-lucky[j].probability, lucky[j].num) * (1-die[i-1][j]);
			}
		}
		for(int i = 1; i <= maxt; i++) {
			for(int h = 0; h < k; h++) {
				double temp = (1 - die[i][h]) - (1 - die[i+1][h]);
				for(int j = 0; j < k; j++) {
					if(j!=h) {
						temp *= die[i][j];
					}
				}
				ans[h] += temp;  
			}
		}
		for(int i = 0; i < k; i++) {
			std::cout << ans[i] << (i==k-1?'\n':' ');
		}
	}
	return 0;
}