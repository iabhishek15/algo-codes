#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
struct __{__(){ios_base::Init i;ios_base::sync_with_stdio(0);cin.tie(0);}}__; 
 
 
 int main() {
    int ans = 0;
    int val = 0;
	for (int i = 2; i < 1000; ++i) {
		int p = 10;
		if (i > 10 && i <= 100) p = 100;
		if (i > 100) p = 1000;
		map<int,bool> m;
		int cnt = 0;
		while (1) {
			int z = p % i;
			if (m[p % i]) break;
			if (!z) {
				cnt++;
				break;
			}
			m[p %  i] = 1;
			p = 10 * z;
			cnt++;
			if (p < i) {
				p = 10 * p;
				cnt++;
			}
		}
		if (cnt > ans) {
			ans = cnt;
			val = i;
		}
	}
	cout << val << " " << ans <<   endl;
 }
