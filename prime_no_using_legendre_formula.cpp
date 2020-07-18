//for less than 1e9 and works in just less than 3 sec

vector<int64_t> prime;
int64_t val;
int p;
//int const sqrt_x = 1e6;
//int64_t dp[sqrt_x];
map<pair<int,int>,int> m;

int phie(int x, int a) {
	auto it = m.find({x,a});
	if (it != m.end()) {
		return m[{x,a}];
	}
	if (a == 0) {
		return (x + 1) / 2;
	}
	return m[{x,a}] = phie(x,a - 1) - phie(x/prime[a],a - 1);
}

int main() {
	IOS;
	cin >> val;
	int n = val;
	vector<bool> ch(1e5 + 1);
	for (ll i = 2; i * i <= n; ++i) {
		if (!ch[i]) {
			prime.push_back(i);
			for (ll j = i; j * j <= n; j += i) {
				ch[j] = 1;
			}
		}
	}
	p =  (int)prime.size();
	int ans = p;
	//debug(ans,prime,n);
	ans += phie(val,p - 1) - 1;
	cout << (int)m.size() << endl;
	cout << ans << endl;
}






