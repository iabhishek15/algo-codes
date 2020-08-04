

vector<int> cnt(1e5 + 1);
vector<int> parent(1e5 + 1);
int n, m;

int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = find(parent[a]);
}

void set_union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) {
		return ;
	}
	if (cnt[a] < cnt[b]) {
		swap(a,b);
	}
	parent[b] = a;
	cnt[a] += cnt[b];
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		parent[i] = i;
		cnt[i] = 1;
	}
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		set_union(x,y);
	}
	for (int i = 1; i <= n; ++i) {
		cout << i << " " << parent[i] << endl;
	}
}


















