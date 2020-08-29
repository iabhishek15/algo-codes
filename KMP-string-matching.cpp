#include <iostream>
#include <vector>
using namespace std;

int main() {
	string s;
	cin >> s;
	string a;
	cin >> a;
	int n = (int)s.size();
	int m = (int)a.size();
	vector<int> index(m);
	for (int i = 1, p = 0; i < m; ++i) {
		if (a[i] == a[p]) {
			p++;
			index[i] = p;
		}else {
			p = 0;
		}
	}
	bool pres = 0;
	int z = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == a[z]) {
			z++;
		}else {
			z = index[z];
		}
		if (z == m) {
			pres = 1;
			break;
		}
	}
	cout << pres << endl;
}



















	

