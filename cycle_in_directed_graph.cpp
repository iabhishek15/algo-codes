//we should iterate over all the elements and check if anyone contains a cycle
//there may be chances that 3 is in cycle with 4 then while traversing across 3 we may not
//get cycle but while travering across 4 we will deinitely will get the cycle

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
