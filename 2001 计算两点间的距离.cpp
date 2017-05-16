#include <iostream>
#include <iomanip>
#include <cmath>

int main(int argc, char *argv[]) {  
	float x1, y1, x2, y2;
	while(std::cin >> x1 >> y1 >> x2 >> y2) {
		std::cout << std::fixed << std::setprecision(2) << sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) << std::endl;
	}
	return 0;
}