#include <iostream> 
 
int main(int argc, char *argv[]) {  
	int m,n,s;  
	while(std::cin >> m >> n && !(m == 0 && n == 0)) {   
		s = m;  
		for(int i = 1; i < n; i++)  
			s=(s * m) % 1000;  
		std::cout << s << std::endl; 
	}  
	return 0;  
} 