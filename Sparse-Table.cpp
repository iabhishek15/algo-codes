#include <bits/stdc++.h> 
using namespace std;
 
typedef long long ll;

int main() {
	//int p[] = {5,2,4,7,6,3,1,2};
	int n;
	cin >> n;
	int x = log2(n) + 1;
	int  p[n];
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	int dp[x][n];
	memset(dp,0,sizeof(dp));
	//n - pow(2,i) + 1
//4 2 , 2 //j + pow(2,i) ,  
	for (int i = 0; i < n; ++i) {
		dp[0][i] = p[i];
	} 
	for (int i = 1; i < x; ++i) {
		int fp = pow(2,i - 1);
		for (int j = 0; j < n; ++j) {
			//int first = j + fp;
			if (j < n - pow(2,i) + 1) {
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + fp]);
			}else {
				dp[i][j] = dp[i][j - 1];
			}
		}
	}
	//for (int i = 0; i < x; ++i) {
		//for (int j = 0; j < n; ++j) {
			//cout << dp[i][j] << " ";
		//}
		//cout << endl;
	//}
	
	//for (int i = 0; i < n; ++i) {
		//cout << p[i] << " ";
	//}
	//cout << endl;
	
	//for (int i = 0; i < x; ++i) {
		//for (int j = 0; j < n; ++j) {
			//cout << dp[i][j] << " ";
		//}
		//cout << endl;
	//}
	//cout << endl;
	//for searching the value 
	//(left, right)
	// x = log2(right - left);
	// y = right - x;
	//min(dp[left][x],dp[x + 1,y]);;
	int k;
	cin >> k;
	while (k--) {
		int left, right;
		cin >> left >> right;
		left--;
		right--;
		int total = right - left + 1;
		int log = log2(total);
		int z = pow(2,log);
		//int rem = right - (left + log) + 1;
		int ans = min(dp[log][left],dp[log][right - z + 1]);
		//cout << log << " " << left << endl;
		//cout << log << " " << left + z << endl;
		cout << ans << endl;
 	}
}





















