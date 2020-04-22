#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> v(100);
vector<bool> visited(100);
deque<int> p;

struct bfs{
    void add(int a, int b) {
		v[a].push_back(b);
		v[b].push_back(a);
	}	
	void printing(int a) {
		if (!visited[a]) {
			visited[a] = 1;
			cout << a << endl;
		}
		for (auto x : v[a]) {
			if (!visited[x]) {
				cout << x << endl;
				p.push_back(x);
				visited[x] = 1;	
			}
		}

		while(!p.empty()){
			int x = p.front();
			p.pop_front();
		//	if (!visited[x]) {
		//		visited[x] = 1;
				printing(x);
	   //		}
		}
	}
	
};


int main() {
    bfs b;
    b.add(1,4);	
    b.add(1,2);	
    b.add(2,5);	
    b.add(2,3);	
    b.add(3,6);	
    b.add(5,6);	
    b.printing(1);
}
