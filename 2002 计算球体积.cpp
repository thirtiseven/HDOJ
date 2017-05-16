#include <iostream>
#include <iomanip>
#include <cmath>

#define pi 3.1415927

int main(int argc, char *argv[]) {  
	double r;
	while(scanf("%lf", &r) != EOF) {
		std::cout << std::fixed << std::setprecision(3) << 4.0 * pi * r * r * r / 3.0 << std::endl;
	}
	return 0;
}