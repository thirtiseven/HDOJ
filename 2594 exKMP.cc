#include <iostream>
#include <algorithm>
#include <string>

const int maxn = 10007;
int ans, nexr[maxn], ex[maxn];
void getnexr(std::string s) {
	int i = 0, j, po, len = s.length();
	nexr[0] = len;
	while (s[i] == s[i+1] && i + 1 < len) i++;
	nexr[1] = i;
	po = 1;
	for (i = 2; i < len; i++) {
		if (nexr[i-po] + i < nexr[po] + po) {
			nexr[i] = nexr[i - po];
		} else {
		 	j = nexr[po] + po - i;
		 	if (j < 0) j = 0;
		 	while (i + j < len && s[j] == s[i+j]) j++;
		 	nexr[i] = j;
		 	po = i;
		 }
	}
}

void exkmp(std::string s1, std::string s2) {
	int i = 0, j, po = 0, len = s1.length(), l2 = s2.length();
	while (s1[i] == s2[i] && i < l2 && i < len) i++;
	ex[0] = i;
	for (i = 1; i < len; i++) {
		if (nexr[i - po] + i < ex[po] + po) {
			ex[i] = nexr[i-po];
		} else {
		 	j = ex[po] + po - i;
		 	if (j < 0) j = 0;
		 	while (i + 1 < len && s1[j+i] == s2[j]) j++;
		 	ex[i] = j;
		 	po = i;
		 }
	}
}

int main(int argc, char *argv[]) { 
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int ans = 0; 
	std::string s1, s2;
	while (std::cin >> s1 >> s2) {
		ans = 0;
		getnexr(s1);
		exkmp(s2, s1);
		for (int i = 0; i < s2.length(); i++) {
			ans = std::max (ans, ex[i]);
		}
		for (int i = 0; i < ans; i++) {
			std::cout << s1[i];
		}
		if (ans) std::cout << " ";
		std::cout << ans << '\n'; 
	}
}