vector<vector<int>> matmul(vector<vector<int>> a, vector<vector<int>> b) {
	int R = (int)a.size();
	int C = (int)b[0].size();
	int Z = (int)b.size();
	vector<vector<int>> res(R, vector<int> (C));
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			for (int k = 0; k < Z; ++k) {
				res[i][j] += a[i][k] * b[k][j]; 
			}
		}
	}
	return res;
}
