#include <iostream>
#include <cmath>
#include <algorithm>

int main(int argc, char *argv[]) {
	int CAS;
	double t, v1, v2;
	std::cin >> CAS;
	for(int case_now = 1; case_now <= CAS; case_now++) {
		std::cin >> t >> v1 >> v2;
		bool win = 0;
		if(v1 >= v2) {
			win = 1;
		} else if (v1 >= v2 / sqrt(2)) {
			double t2 = (2 * v2 + sqrt(4 * pow(v2, 2) - 8 * (pow(v2, 2) - (pow(v1, 2))))) / (2 * (pow(v2, 2) - (pow(v1, 2))));
			if((v2 * t2) / v1 <= 2.0 / v2 + t) {
				if((v2 * t2) / v1 + 1.0 / v1 <= 2.0 / v2 + t + 1.0 / v2) {
					win = 1;
				} else {
					win = 0;
				}
			} else {
				win = 0;
			}
		} else if (v1 >= v2 / 3.0) {
			
		} else {
			win = 0;
		}
		if(win) {
			std::cout << "Case #" << case_now << ": YES\n";
		} else {
			std::cout << "Case #" << case_now << ": NO\n";
		}
	}
	return 0;
}