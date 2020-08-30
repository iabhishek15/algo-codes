void check_pattern() {
	int mod = 1e9 + 7;
	int z = 127;
	string a, b;
	cin >> a >> b;
	int n = (int)a.size();
	int m = (int)b.size();
	if (m > n) {
		cout << "Not Found\n\n";
		return ;
	}
	auto check = [&] (int st, int en) -> bool{
		int p = 0;
		for (int i = st; i <= en; ++i) {
			if (a[i] != b[p]) return 0;
			p++;
		}
		return 1;
	};
	int64_t val = 0, curr_val = 0;
	vector<int> ans;
	for (int i = 0; i < m; ++i) {
		int x = b[i] - '0' + 1;
		val = (val + x * power_mod(z, m - i - 1, mod)) % mod;
		int y = a[i] - '0' + 1;
		curr_val = (curr_val + y * power_mod(z, m - i - 1, mod)) % mod;
		if (i == m - 1 && curr_val == val && check(0, m - 1)) {
			ans.push_back(1);
		}
	}
	for (int i = m; i < n; ++i) {
		int x = a[i] - '0' + 1;
		int y = a[i - m] - '0' + 1;
		int val_z = (y * power_mod(z, m - 1, mod)) % mod; 
		curr_val = (((curr_val - val_z + mod) % mod * z) + x) % mod;
		if (curr_val == val && check(i - m + 1, i)) {
			ans.push_back(i - m + 2);
		}  
	}
	int k = (int)ans.size();
	if (k > 0) {
		cout << k << "\n";
		for (int i = 0; i < k; ++i) {
			cout << ans[i] << " ";
		}
	}else {
		cout << "Not Found";
	}
	cout << "\n\n";
}
