#include "bits/stdc++.h"
using namespace std;

int const INF = 1e7;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int,int>>> v(n + 1);
	vector<int> ans(n + 1);
	for (int i = 0; i < m; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		v[x].push_back({y,z});
	}
	for (int i = 2; i <= n; ++i) {
		ans[i] = INF;
	}
	ans[1] = 0;
	int e = n - 1;
	while (e--) {
		queue<int> q;
		q.push(1);
		vector<int> visited(n + 1);
		while (!q.empty()) {
			int f = q.front();
			for (auto x : v[f]) {
				int a = x.first;
				int b = x.second;
				ans[a] = min(ans[a], ans[f] + b);
				if (!visited[a]) {
					q.push(a);
				}
			}
			visited[f] = 1;
			q.pop();
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	 }
}	

//points to remember
//1) we find the shortest path from a node to every other node
//2) we assign that root to 0 and all other to infinity
//3) we iterate over all edges (edges - 1 times)
//4) we can dfs or bfs
//5) in case of complete graph it can take n^3 time
//6) it does not work there is negitive weight cycle 
//(as in each step we can get path of lesser length)
