#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
struct __{__(){ios_base::Init i;ios_base::sync_with_stdio(0);cin.tie(0);}}__; 
 
int dp[10099][2009];
 
 int main() {
	int l = 1008;
	dp[0][l] = 1;
	dp[1][l] = 1;
	int w = l - 2;
	for (int i = 2; i < 10000; ++i) {
		int carry = 0;
		int d = 0;
		for (int k = l; k > w; --k) {
			int x = dp[i - 1][k] + dp[i - 2][k] + carry;
			carry = x / 10;
			dp[i][k] = x  % 10;  
			if (dp[i][k] != 0) {
			  d = l - k + 1;
		    }	
		}
		w -= 2;
		w = max(0,w);
		if (d >= 1000) {
			cout << i << endl;
			return 0;
		}
	}
 }
 
