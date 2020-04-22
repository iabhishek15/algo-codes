#include "bits/stdc++.h"
using namespace std;

int const INF = 1e7;
int n;
int p = 100;
vector<vector<int>> v(p);
map<pair<int,int>, int> m;
vector<bool> check(p);
vector<int> val(p,INF);
deque<int> res;
class graph {
public:
	void add(int a, int b, int c) {
		m[{a,b}] = c;
		m[{b,a}] = c;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	void get(int a) {
		val[a] = 0;
        for (int i = 0; i < n - 1; ++i) {
			print(a);
			clear();
		}		
	}
	void print(int a) {
		for (auto x : v[a]) {
			if (!check[x]) {
				res.push_back(x);
				val[x] = min(val[x], val[a] + m[{a,x}]);
			}
		}
		check[a] = 1;
		while (!res.empty()) {
			int y = res.front();
			res.pop_front();
			print(y);
		}
	}

	void clear() {
		for (int i = 0; i < p; ++i) {
			check[i] = 0;
		}
	}
};


int main() {
	graph g;
	n = 5;
	//p = n + 2;
	g.add(1,3,3);
	g.add(1,2,5);
	g.add(1,4,7);
	g.add(3,4,1);
	g.add(4,5,2);
	g.add(2,5,2);
	g.add(2,4,3);
	g.get(1);
	for (int i = 0; i < p; ++i) {
		if (val[i] != INF) {
			cout << "1 -> " << i << " : " << val[i] << endl;
		}
	}
}
