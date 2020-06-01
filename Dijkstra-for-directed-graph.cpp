#include <bits/stdc++.h> 
using namespace std;

int INF = 1e9 + 7;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int,int>>> v(n);
	for (int i = 0; i < m; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		x--, y--;
		v[x].push_back({y,z});
	}
	vector<int> ans(n);
	vector<bool> p(n);
	set<pair<int,int>> s;
	for (auto x : v[0]) {
		s.insert({x.second, x.first});
		ans[x.first] = x.second;
		p[x.first] = 1;
	}
	p[0] = 1;
	for (int i = 0; i < n; ++i) {
		if (!p[i]) {
			s.insert({INF,i});
			ans[i] = INF;
		}
	}
	ans[0] = 0;	 
	while (!s.empty()) {
		auto it = s.begin();
		ans[it->second] = it->first;
		for (auto x : v[it->second]) {
			auto tt = s.find({ans[x.first],x.first});
			if (ans[x.first] == INF && ans[it->second] == INF) 
				ans[x.first] = INF; 
			else 
				ans[x.first] = min(ans[x.first],ans[it->second] + x.second);
			if (tt != s.end()) {
				s.erase(tt);
				s.insert({ans[x.first],x.first});
			}
		}	
		s.erase(it);
 	}
 	for (int i = 0; i < n; ++i) {
		cout << i << " " << ans[i] << endl;
	}
}


//points to remember
//1) time complexity is n^2 
//2) dijikstra algorithm may and may not work with negitive edge
