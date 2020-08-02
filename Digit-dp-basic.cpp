#pragma GCC optimize("Ofast")
#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

string int_to_string(int64_t x) {
    stringstream ss;
	ss << x;
	string ni = ss.str();
	return ni;
}
int64_t string_to_int(string x) {
	int64_t n;
	stringstream s(x);
	s >> n;
	return n;
}

int64_t a, b;
string s_a, s_b;
string p = "0123456789";

int64_t dp[18][162 + 1][2];

int64_t rec(string &s, int index, bool last, int64_t last_sum)  {
    if (index == (int)s.size()) {
		return 0;
	} 
	if (dp[index][last_sum][last] != -1) {
		return dp[index][last_sum][last];
	}
	int64_t sum = 0;
	for (int i = 0; i <= 9; ++i) {
		if (p[i] > s[index] && !last) {
			break;
		}
		if (p[i] != '0')
			sum += (p[i] - '0' + last_sum);
		if (p[i] < s[index] || last) {
			sum += rec(s, index + 1, 1, last_sum + p[i] - '0');
		}else {
			sum += rec(s, index + 1, 0, last_sum + p[i] - '0');
		}
	}
	return dp[index][last_sum][last] = sum;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> a >> b;
		s_a = int_to_string(a - 1);
		s_b = int_to_string(b);
		memset(dp, -1, sizeof(dp));
		int64_t ans_b = rec(s_b, 0, 0, 0LL);
		memset(dp, -1, sizeof(dp));
		int64_t ans_a = 0;
		if (a > 0) {
			ans_a = rec(s_a, 0L, 0, 0LL);
		}
		cout << ans_b - ans_a << endl;
	}
}












