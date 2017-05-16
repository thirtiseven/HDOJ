#include <iostream>
#include <cmath>
#include <iomanip>

int main(int argc, char *argv[]) {  
	int n, m;
	double sum = 0.0, temp;
	while(std::cin >> n >> m) {
		temp = (double)n;
		for(int i = 0; i < m; i++) {
			sum += temp;
			temp = sqrt(temp);			
		}
		std::cout << std::fixed << std::setprecision(2) << sum << std::endl;
		sum = 0;
	}
	return 0;
}