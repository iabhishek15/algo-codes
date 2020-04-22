#include "bits/stdc++.h"
using namespace std;

int const INF = 1e9;
int const p = 100;
//priority_queue <vector<int>, vector<vector<int>>, greater<int> > pq; 
vector<vector<pair<int,int>>> v(p);
vector<int> val(p,INF);
vector<bool> visited(p);
deque<int> d;

class graph{
public:
	void add(int a, int b, int c) {
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	void calling(int a) {
		int minn = INF;
		int b = 0;
		for (auto x : v[a]) {
			if (visited[x.first]) {
				if (x.second < minn) {
					minn = x.second;
					b = x.first;
				}
				deque.push_back(x.first);n
			}
		}
		visited[a] = 1;
		while (!d.empty()) {
			int p = d.front();
			d.pop_front();
			calling(p);
		}
	}
};


int main() {
	graph g;
	g.add(2,3,2);
	g.add(3,4,6);
	g.add(2,1,5);
	g.add(4,1,9);
	g.add(4,5,2);
	g.add(5,1,1);
	g.calling(1);
}
