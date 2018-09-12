#include <iostream>
#include <vector>
#include <cstring>

const int maxn = 100007;

using ll = long long;
int n, MAX_BASE = 60;
ll a[maxn], b[63];
bool zero = false;
ll cnt = 0;

void cal() {
	memset(b, 0, sizeof b);
	for (int i=0; i<n; i++) for(int j=MAX_BASE; j>=0; j--) {
		if ((a[i]>>j)&1) {
			if(b[j]) a[i]^=b[j];
			else {
				b[j] = a[i], cnt++;
				for (int k=j-1; k>=0; k--)			 if (b[k]&&((b[j]>>k)&1)) 	b[j] ^= b[k];
				for (int k=j+1; k<=MAX_BASE; k++)	 if ((b[k]>>j)&1) 			b[k] ^= b[j];
				break;
			}
		}
	}
	zero = cnt != n;
}

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	for (int CA = 1; CA <= T; CA++) {
		zero = false;
		cnt = 0;
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		cal();
		std::vector<ll> ss;
		ss.clear();
		for (int i = 0; i < MAX_BASE; i++) {
			if (b[i]) ss.push_back(b[i]);
		}
		int q;
		ll t;
		std::cin >> q;
		std::cout << "Case #" << CA << ":\n";
		for (int i = 0; i < q; i++) {
			std::cin >> t;
			if (zero) t--;
			ll ans = 0;
			if (t >= (1LL << (int)ss.size())) {
				ans = -1;
			} else {
				for (int i = 0; i < (int)ss.size(); ++i) 
				if ((t >> i) & 1)
					ans ^= ss[i];
			}
			std::cout << ans << '\n';
		}
	}
}