
#include <bits/stdc++.h>
using namespace std;

//problem : https://cses.fi/problemset/task/1687/

vector<int> father(7e5 + 100);
int l = 19;
vector<vector<int>> parents(7e5 + 100, vector<int> (l + 1, 0));
int n, q;

void build_parent_tree() {
	//base condition
	for (int i = 0; i <= n; ++i) parents[i][0] = father[i];
	
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= 19; ++j) {
			parents[i][j] = parents[parents[i][j - 1]][j - 1]; 
		}
	}
}
	
int binary_lifting(int edge, int k) {
	int val = edge;
	for (int i = 0; i <= 19; ++i) {
		if ((k >> i) & 1) {
			val = parents[val][i];
		}
	}
	return ((val == 0)? -1: val);
}

int main() {
	cin >> n >> q;
	for (int i = 0; i < n - 1; ++i) {
		int x;
		cin >> x;
		father[i + 2] = x;
	}
	build_parent_tree();
	while (q--) {
		int edge, k;
		cin >> edge >> k;
		cout << binary_lifting(edge, k) << "\n";
	}
}



































