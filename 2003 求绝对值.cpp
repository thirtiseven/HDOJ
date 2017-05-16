#include <iostream>
#include <iomanip>
#include <cmath>

int main(int argc, char *argv[]) {  
	double r;
	while(scanf("%lf", &r) != EOF) {
		std::cout << std::fixed << std::setprecision(2) << fabs(r) << std::endl;
	}
	return 0;
}