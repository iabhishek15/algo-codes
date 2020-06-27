
:
    bool isCycle(int index, vector<vector<int>> & v, vector<bool> &visited, vector<bool> &rec) {
        if (rec[index]) {
            return 0;
        }
        if (visited[index]) {
            return 1;
        }
        visited[index] = 1;
        for (auto x : v[index]) {
            bool a  = isCycle(x,v,visited,rec);
            if (a) {
                return 1;
            }
        }
        rec[index] = 1;
        return 0;
    }
        
  int main() {
        int p = 1e5 + 7;
        vector<bool> visited(p);
        vector<bool> rec(p);
        vector<vector<int>> v(p);

        for (int i = 0; i < n; ++i) {
            v[pre[i][1]].push_back(pre[i][0]);
        }
        for (int i = 0; i < c; ++i) {
            if (!rec[i] && isCycle(i,v,visited,rec)) {
                return 0;
            }
        }
        return 1;
  }
