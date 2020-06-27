//we should iterate over all the elements and check if anyone contains a cycle
//there may be chances that 3 is in cycle with 4 then while traversing across 3 we may not
//get cycle but while travering across 4 we will deinitely will get the cycle

//here when we return 1 we mean false and when we return 0 we mean true

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
        int p = 1e5 + 7;
        vector<bool> visited(p);
        vector<bool> rec(p);
        vector<vector<int>> v(p);

        for (int i = 0; i < n; ++i) {
            v[pre[i][1]].push_back(pre[i][0]);
        }
        for (int i = 0; i < c; ++i) {
            if (!rec[i] && !dfs(i,v,visited,rec)) {
                return 0;
            }
        }
        return 1;

//it have to test whether the below one is true or not

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
            if (a) {
               //rec[index] = 1;//here we can use this or nott depending accoding to the requirment if  we need the point where cycle is 
                    //formed then we may need it
               return 1;
            }
        }
        rec[index] = 1;
        return 0;
    }
