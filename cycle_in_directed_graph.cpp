    bool dfs(int index, vector<vector<int>> & v, vector<bool> &visited, vector<bool> &rec) {
        if (rec[index]) {
            return 1;
        }
        if (visited[index]) {
            return 0;
        }
        visited[index] = 1;
        for (auto x : v[index]) {
            bool a  = dfs(x,v,visited,rec);
            if (!a) return 0;
        }
        rec[index] = 1;
        return 1;
    }
