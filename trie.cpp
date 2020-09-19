#include <bits/stdc++.h> 
using namespace std;

int const p = 1000000;
int trie[p + 1][26];
int weight[p + 1];
int value[p + 1][26];
int nex = 1;
int n, q;

void build (string &s, int index) {
	for (int c = 0, i = 0; i < (int)s.size(); c = trie[c][s[i] - 'a'], ++i) {
		value[c][s[i] - 'a'] = max(value[c][s[i] - 'a'], weight[index]);
		if (!trie[c][s[i] - 'a']) trie[c][s[i] - 'a'] = nex++;
	}		
}

int query(string &s) {
	int val = 0;
	int step = 0;
	int i = 0;
	while (trie[step][s[i] - 'a'] && i < (int)s.size()){
		val = value[step][s[i] - 'a'];
		step = trie[step][s[i++]- 'a'];
	}
	return (i == (int)s.size())?val: -1;
}

int main() {
	cin >> n >> q;
	vector<string> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i] >> weight[i];
	for (int i = 0; i < n; ++i) build(v[i], i);
	while (q--) {
		string s;
		cin >> s;
		cout << query(s) << "\n";
	}
}
