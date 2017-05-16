#include <iostream>

int main(int argc, char *argv[]) {  
	int daff[5] = {153, 370, 371, 407};
	int begin, end, flag = 1;
	while(std::cin >> begin >> end) {   
		if(begin > end) {
			std::cout << "no\n";
			continue;
		}
		for(int i = 0; i < 4; i++) {
			if(daff[i] <= end && daff[i] >= begin) {
				if(!flag) {
					std::cout << " ";
				}
				std::cout << daff[i];
				flag = 0;
			}
		}
		if(flag) {
			std::cout << "no\n";
		} else {
			std::cout << "\n";
		}
		flag = 1;
	}
	return 0;
}