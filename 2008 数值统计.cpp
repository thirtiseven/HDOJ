#include <iostream>
  
int main(int argc, char *argv[]){  
	int n,a,b,c,i;  
	double temp;  
	while(std::cin >> n && n != 0) {  
		a=0;
		b=0;
		c=0;  
		for(i=0;i<n;i++) {  
			std::cin >> temp; 
			if(temp > 0) {
				a++;
			} else if(temp == 0) {
				b++;
			} else {
				c++;
			}  
		}  
		std::cout << c << " " << b << " " << a << std::endl;
	}  
	return 0;  
} 