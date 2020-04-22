#include "bits/stdc++.h"
using namespace std;

vector<int> visited(100);
vector<vector<int>> v(100);

struct dfs{
    void add(int a, int b) {
		v[a].push_back(b);
		v[b].push_back(a);
	}
	void calling(int a) {
		if (visited[a]) {
			return ;
		}
		cout << a  << endl;
		visited[a] = 1;
		for (auto x : v[a]) {
			calling(x);
		} 
	}
};


int main() {
	dfs d;
	d.add(1,4);
	d.add(1,2);
	d.add(2,5);
	d.add(2,3);
	d.add(3,5);
	d.calling(1);
}
