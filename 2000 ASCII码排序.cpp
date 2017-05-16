#include <iostream>
#include <cstring>
#include <algorithm>

int main(int argc, char *argv[]) { 
	char test[5]; 
	while(std::cin >> test) {
		std::sort(test, test + 3);
		std::cout << test[0] << " " << test[1] << " " << test[2] << std::endl;
	}
	return 0; 
}