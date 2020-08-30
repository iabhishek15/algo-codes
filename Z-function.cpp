void check_pattern() {
	string a, b;
	cin >> a >> b;
	string s = b + "$" + a;
	int n = (int)s.size();
	int b_size = (int)b.size();
	vector<int> ans;
	vector<int> Z(n);
	int L = 0, R = 0;
	for (int i = 1; i < n; ++i) {
		if (i > R) {
			L = R = i;
			while (R < n && s[R] == s[R - L]) {
				R++;
			}
			Z[i] = R - L;
			R--;
		}else {
			int k = i - L;
			if (Z[k] < R - i + 1) {
				Z[i] = Z[k];
			}else {
				L = i;
				while (R < n && s[R] == s[R - L]) {
					R++;
				}
				Z[i] = R - L;
				R--;
			}
		}
	}	
	for (int i = 0; i < n; ++i) {
		if (Z[i] == b_size) {
			ans.push_back(i - b_size);
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
