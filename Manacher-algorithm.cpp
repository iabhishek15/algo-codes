//here main concept is the mirror image around a point
// a b c b a 
// 0 1 2 3 4
//here mirror point is at index 2 so if we are at index 3 we can use the mirror alphabet of this value which is at index 1 
//so index 1 will give its length since it's left lenght can be more than the actual element in mirror form
//thats why left point comes into picture. so max point should not be more than r - i
///at we can also replace since value more than that will go outside the scope of mirror range. (which is unessary)
///

//small code for the same algo
int palindrome(string &a) {
	string s = "#";
	for (int i = 0; i < (int)a.size(); ++i) s += a[i], s += "#";
	int n = (int)s.size();
	vector<int> dp(n);
	int l = 0, r = 0;
	for (int i = 0; i < n; ++i) {
		dp[i] = min(dp[r - i + l], r - i);
		while (i - dp[i] - 1 >= 0 && i + dp[i] + 1 < n && s[i - dp[i] - 1] == s[i + dp[i] + 1]) dp[i]++;
		if (i + dp[i] > r) r = i + dp[i], l = i - dp[i];
	}
	int max_ans = 0;
	for (int i = 0; i < n; ++i) {
		int val = dp[i];
		if (s[i] == '#' && dp[i] % 2 == 1)val++;
    if (s[i] != '#' && dp[i] % 2 == 0)val++;
		max_ans = max(max_ans, val);
	}
	return max_ans;
}




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

