#include <iostream>
#include <algorithm>
#include <cstring>

const int maxn = 999999 + 9;
int a[maxn];

int main(int argc, char *argv[]) { 
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int n;
	while (std::cin >> n) {
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::nth_element(a, a+n/2, a+n);
		std::cout << a[n/2] << '\n';
	}
}