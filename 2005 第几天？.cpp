#include <iostream>

int main(){
	int y,m,d;
	int days[12]={0,31,59,90,120,151,181,212,243,273,304,334};
	char ch;
	while(std::cin >> y >> ch >> m >> ch >> d){
		int ans = days[m-1];
		ans += d;
		if(((y % 4==0 && y % 100!=0) || y % 400==0) && m>2) ans++;
		std::cout << ans << std::endl;
	}
	return 0;
}
