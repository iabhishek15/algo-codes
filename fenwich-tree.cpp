#include <bits/stdc++.h> 
using namespace std;
int const t = 10000;
int n;
int v[t + 1];
int p[t + 1];

void update(int a, int b) {
	for ( ; a <= n; a += a & -a) {
		p[a] += b;
	} 
}

int query(int a) {
	int sum = 0;
	for ( ; a > 0; a -= a & -a) {
		sum += p[a];
	}
	return sum; 
}


int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; ++i) {
		update(i, v[i]);
	}
	int m;
	cin >> m;
	while (m--) {
		int left, right;
		cin >> left >> right;
		cout << query(right) - query(left - 1) << endl;
	}
}





















