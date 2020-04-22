#include <bits/stdc++.h> 
using namespace std;
int pos = 1e4;
int n;
vector<int> v(pos);
vector<int> a(pos);

void build_segment_tree(int start, int end, int index) {
	if (start == end) {
		v[index] = a[start]; 
		return ;
	}
	int mid = (start + end) / 2;
	build_segment_tree(start, mid, index*2);
	build_segment_tree(mid + 1,end, index*2 + 1);
	
	v[index] = v[index*2] + v[index*2 + 1];
}

int query_segment(int x, int y, int start, int end, int index) {
	if ((start >= x) &&  (end <= y)) {
		return v[index];
	}
	if ((y < start) || (x > end)) {
		return 0;
	} 
	int mid = (start + end) / 2;
	return query_segment(x, y, start, mid, index * 2) + query_segment(x, y, mid + 1, end, index * 2 + 1);
}

void query_update(int given_index, int value, int start, int end, int index) {
	v[index] += value;
	if (start == end) {
		return ;
	}
	int mid = (start + end) / 2;
	if (given_index <= mid) {
		query_update(given_index, value, start, mid, index * 2);
	}else {
		query_update(given_index, value, mid + 1, end, index * 2 + 1);
	}
}



int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	build_segment_tree(0, n - 1, 1);
	int k;
	cin >> k;
	while (k--) {
		int x;
		cin >> x;
		if (x == 2) {
			int left, right;
			cin >> left >> right;
			left--;
			right--;
			cout << query_segment(left, right, 0, n - 1, 1) << endl;
		}else {
			int index;
			int value;
			cin >> index >> value;
			index--;
			int lo = value - a[index];
			a[index] = value;
			query_update(index, lo, 0, n - 1, 1);
		}
	}
}










