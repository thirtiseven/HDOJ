#include <iostream>
#include <iomanip>
#include <cmath>

int main(int argc, char *argv[]) {  
	int g;
	while(std::cin >> g) {
		if(g > 100 || g < 0) {
			std::cout << "Score is error!\n";
		} else if(g >= 90) {
			std::cout << "A\n";
		} else if(g >= 80) {
			std::cout << "B\n";
		} else if(g >= 70) {
			std::cout << "C\n";
		} else if(g >= 60) {
			std::cout << "D\n";
		} else {
			std::cout << "E\n";
		}
	}
	return 0;
}