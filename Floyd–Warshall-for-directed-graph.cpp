#include "bits/stdc++.h"
using namespace std;

int INF = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(n, vector<int> (n, INF));
    
    for (int i = 0; i < m; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		x--;
		y--;
		dp[x][y] = z; 
		dp[x][x] = 0;
		dp[y][y] = 0;
	}   
	for (int k = 0; k < n; ++k) {
		vector<vector<int>> val(n, vector<int> (n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i != j) {
					if (dp[i][j] == INF && (dp[i][k] == INF || dp[k][j] == INF)) 
						val[i][j] = INF;
					else 
						val[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]); 
				}
			}
		}
		dp = val;
	}
	for (int i = 0; i < n; ++i) {
	    for (int j = 0; j < n; ++j) {
			cout << dp[i][j] << " ";
		}	
		cout << endl;
    }
}
