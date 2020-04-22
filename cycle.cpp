#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> v(100);
vector<bool> visited(100);
deque<int> p;
int cnt = 0;
struct bfs{
    void add(int a, int b) {
		v[a].push_back(b);
		v[b].push_back(a);
	}	
	void printing(int a) {
		if (!visited[a]) {
			visited[a] = 1;
			//cout << a << endl;
		}
		for (auto x : v[a]) {
			if (!visited[x]) {
			 //	cout << a << endl;
			//	cout << x << endl;
				p.push_back(x);
				visited[x] = 1;	
			}else {
				cnt++;
				//cout << a << " " << x <<  endl;
			}
		}
		while(!p.empty()){
			int x = p.front();
			p.pop_front();
				printing(x);
		}
	}
	
};


int main() {
    bfs b;
    b.add(1,4);	
    b.add(1,3);	
    b.add(3,4);	
    b.add(2,3);	
    b.add(3,5);	
    b.add(5,2);	
    b.printing(1);
    cout << cnt;
}
