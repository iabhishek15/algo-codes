

vector<int> cnt(1e5 + 1);
vector<int> parent(1e5 + 1);
int n, m;

int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = find(parent[a]); //this is done so that all the values in set get assigned to single parent
	//so that we can get the answer in O(1) time
	//4->3->1    4->1<-3
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
	cnt[a] += cnt[b]; //union by rank and union by size //this is union by size
	//this is done so that the formation of skewed tree can be avoided 
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


















