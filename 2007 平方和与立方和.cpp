#include <iostream>
#include <cmath>
#include <algorithm>

int main(int argc, char *argv[]) {  
	long long begin, end, sumo = 0, sume = 0;
	while(std::cin >> begin >> end) {
		if(begin > end) {
			std::swap(begin, end);
		}
		for(long long i = begin; i <= end; i++){
			if(i % 2 == 1) {
				sumo += pow(i, 3);
			} else {
				sume += pow(i, 2);
			}
		}
		std::cout << sume << " " << sumo << std::endl;
		sumo = 0;
		sume = 0;
	}
	return 0;
}