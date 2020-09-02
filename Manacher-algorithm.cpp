int palindrome(string &a) {
	string s = "#";
	for (int i = 0; i < (int)a.size(); ++i) {
		s += a[i];
		s += "#";
	}
	int n = (int)s.size();
	vector<int> dp(n);
	int l = 0;
	int r = 0;
	for (int i = 0; i < n; ++i) {
		dp[i] = min(dp[r - i + l], r - i);
		while (i - dp[i] - 1 >= 0 && i + dp[i] + 1 < n && s[i - dp[i] - 1] == s[i + dp[i] + 1]) {
			dp[i]++;
		}
		if (i + dp[i] > r) {
			r = i + dp[i];
			l = i - dp[i];
		}
	}
	int max_ans = 0;
	for (int i = 0; i < n; ++i) {
		int val = 0;
		if (s[i] == '#') {
			if (dp[i] % 2 == 1) {
				val = dp[i] + 1;
			}else {
				val = dp[i];
			}
		}else {
			if (dp[i] % 2 == 1) {
				val = dp[i];
			}else {
				val = dp[i] + 1;
			}
		}
		max_ans = max(max_ans, val);
	}
	return max_ans;
}

