#include "bits/stdc++.h"
using namespace std;

int const nax = 20000 + 5;
vector<unordered_map<int, int>> weight(nax);
vector<vector<int>> adj(nax);
int parent[nax], depth[nax], heavy[nax], head[nax], pos[nax], v[nax];
int cur_pos;
int segment_tree[4 * nax + 100];
int n;

void build_segment_tree(int l = 1, int r = n, int index = 1) {
   if (l == r) {
      segment_tree[index] = v[l];
      return ;
   }
   int half = (l + r) / 2;
   build_segment_tree(l, half, index * 2);
   build_segment_tree(half + 1, r, index * 2 + 1); 
   segment_tree[index] = max(segment_tree[index * 2], segment_tree[index * 2 + 1]);
}

void segment_tree_update(int in, int val, int l = 1, int r = n, int index = 1) {
   if (l == r) {
      segment_tree[index] = val;
      return ;
   }
   int mid = (l + r) / 2;
   if (in <= mid) {
      segment_tree_update(in, val, l, mid, index * 2);
   }else {
      segment_tree_update(in, val, mid + 1, r, index * 2 + 1);
   }
   segment_tree[index] = max(segment_tree[index * 2], segment_tree[index * 2 + 1]);
   
}

int segment_tree_query(int l, int r, int x = 1, int y = n, int index = 1) {
   if (l <= x && r >= y) {
      return segment_tree[index];
   } 
   if (y < l || x > r) {
      return 0;
   }
   int mid = (x + y) / 2;
   return max(segment_tree_query(l, r, x, mid, index * 2), segment_tree_query(l, r, mid + 1, y, index * 2 + 1));
}

int dfs(int val = 1) {
    int size = 1;
    int max_c_size = 0;
    
    for (int c : adj[val]) {
        if (c == parent[val]) continue;
         parent[c] = val, depth[c] = depth[val] + 1;
         int c_size = dfs(c);
         size += c_size;
         if (c_size > max_c_size)
             max_c_size = c_size, heavy[val] = c;
    }
    
    return size;
}

void decompose(int val = 1, int h = 1) {
   v[cur_pos] = weight[val][parent[val]];
   head[val] = h, pos[val] = cur_pos++;
   
   if (heavy[val] != -1) 
     decompose(heavy[val], h);
   for (int c : adj[val]) {
     if (c != parent[val] && c != heavy[val])
         decompose(c, c);
   }
} 

void clearing() {
   for (int i = 0; i <= n; ++i) 
      adj[i].clear(), weight[i].clear();
   for (int i = 0; i <= 4 * n; ++i) 
      segment_tree[i] = 0;
   for (int i = 0; i <= n; ++i) {
      heavy[i] = -1;
      parent[i] = 0;
      v[i] = 0;
      head[i] = 0;
      depth[i] = 0;
   }
}

int query(int a, int b) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = segment_tree_query(pos[head[b]], pos[b]);
        res = max(res, cur_heavy_path_max);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    //if (a == b) return res; 
    int last_heavy_path_max = segment_tree_query(pos[a] + 1, pos[b]);
    res = max(res, last_heavy_path_max);
    return res;
}

void solve() {
   cin >> n;
   cur_pos = 0;
   for (int i = 0; i <= n; ++i) heavy[i] = -1;
   
   vector<pair<int,int>> edge(n + 1);
   for (int i = 0; i < n - 1; ++i) {
      int x, y, w; cin >> x >> y >> w;
      adj[x].push_back(y); weight[x][y] = w;
      adj[y].push_back(x); weight[y][x] = w;
      edge[i + 1].first = x;  
      edge[i + 1].second = y;  
   }
   
   dfs();
   decompose();
   build_segment_tree();
   
   while (1) {
      string s; cin >> s;
      if (s == "DONE") break;
      if (s == "QUERY") {
         int x, y; cin >> x >> y; 
         cout << query(x, y) << "\n";
      }else {
         int x, val; cin >> x >> val; 
         if (parent[edge[x].first] == edge[x].second) 
            segment_tree_update(pos[edge[x].first], val);
         else 
            segment_tree_update(pos[edge[x].second], val);
      }
   }
   
   clearing();
}

int32_t main() {
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int TC; cin >> TC;
   while (TC--) {
      solve();
   }
   return 0;
}






