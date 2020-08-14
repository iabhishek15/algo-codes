#include <iostream> 
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;

#define endl "\n"
#define watch(x) cout << #x << " : " << x << endl;

int in(char a) { 
	return a - '0';
}
string int_to_string(int x) {
    stringstream ss;
	ss << x;
	string ni = ss.str();
	return ni;
}

int dp[11][9 * 10 + 1][9 * 100 + 1][2];
int K;
string A, B;
	
int rec(string& S) {
	int N = (int)S.size();
	for (int digit = 0; digit <= 9; ++digit) {
		if (digit == in(S[0])) {
			dp[0][digit][digit % K][0]++;
		}else if (digit < in(S[0])) {
			dp[0][digit][digit % K][1]++;
		}
 	}
	for (int i = 1; i < N; ++i) {
		for (int sum = 0; sum <= 9 * i; sum++) {
			for (int rem = 0; rem <= min(K - 1, 900); ++rem) {
				for (bool sign : {false, true}) {
					for (int digit = 0; digit <= 9; ++digit) {
						int total = sum + digit;
						int new_rem = (digit + rem * 10) % K;
						if (!sign && digit > in(S[i])) {
							break;
						}
						dp[i][total][new_rem][sign | (digit < in(S[i]))] += dp[i - 1][sum][rem][sign];
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= 9 * N; ++i) {
		if (i % K == 0) {
			ans += dp[N - 1][i][0][0] + dp[N - 1][i][0][1];
		}
	}
	return ans;
}


int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc;
	cin >> tc;
	int p = 1;
	while (tc--) {
		int A_int, B_int;
		cin >> A_int >> B_int >> K;
		A = int_to_string(A_int - 1);
		B = int_to_string(B_int);
		memset(dp, 0, sizeof(dp));
		int ans_b = rec(B);
		memset(dp, 0, sizeof(dp));
		int ans_a = rec(A);
		cout << "Case " << p << ": " << ans_b - ans_a << endl;
		p++;
	}
}




//************************************************************************************************************************

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
//https://atcoder.jp/contests/dp/tasks/dp_s
//https://atcoder.jp/contests/abc135/tasks/abc135_d
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












