#include <iostream>
#include <cmath>

int main(int argc, char *argv[]) {  
	int n, num, sum = 1;
	while(std::cin >> n) {
		for(int i = 0; i < n; i++){
			std::cin >> num;
			if(num % 2 == 1) {
				sum *= num;
			}
		}
		std::cout << sum << std::endl;
		sum = 1;
	}
	return 0;
}