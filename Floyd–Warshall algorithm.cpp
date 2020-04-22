#include "bits/stdc++.h"
using namespace std;
int INF = 1000;
int const n = 5;
int res[n + 1][n + 1];

class graph {
public:
	void add(int a, int b, int c) {
		a--;
		b--;
		res[a][b] = c;
		res[b][a] = c;
		res[a][a] = 0;
		res[b][b] = 0;
	}
	void call() {
		//for (int i = 0; i < n; ++i) {
			//for (int j = 0; j < n; ++j) {
				//cout << res[i][j] << " ";
			//}
			//cout << endl;
		//}
		//cout << endl;
	}

	void get() {
		for (int k = 0; k < n; ++k) {
			int val[n + 1][n + 1];
			memset(val,INF,sizeof(val));
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (i == j) {
						val[i][j] = 0;
					}else {
					    int x = res[i][k] + res[k][j];
					    if (x < res[i][j]) {
							val[i][j] = x;
						}else {
							val[i][j] = res[i][j];
						}
					}
				}
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					res[i][j] = val[i][j];
				}
			}
		}
	}
};

int main() {
	graph g;
	//memset(res,INF,sizeof(res));
	for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				//cout << res[i][j] << " ";
				res[i][j] = INF;
			}
			//cout << endl;
		}
		//cout << endl;
	g.add(2,3,2);
	g.add(3,4,7);
	g.add(4,1,9);
	g.add(2,1,5);
	g.add(1,5,1);
	g.add(4,5,2);
	g.call();
	g.get();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}
