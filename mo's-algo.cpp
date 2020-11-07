#include "bits/stdc++.h"
using namespace std;

int BLOCK = 555;

struct query {
    int l, r, i;
};
 
bool comp(query a , query b) {
   if(a.l / BLOCK != b.l / BLOCK)
      return a.l / BLOCK < b.l / BLOCK;
   return a.r < b.r;
}

query q[200000 + 1];
int m[1000000 + 1];
int v[30000 + 1];

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n, qq; 
   cin >> n;
   for (int i = 0; i < n; ++i) cin >> v[i];
   cin >> qq;
   for (int i = 0; i < qq; ++i) {
      cin >> q[i].l >> q[i].r;
      q[i].i = i; q[i].l--, q[i].r--;
   }
   sort(q, q + qq, comp);
   int cnt = 0;
   auto add = [&](int val) {
      m[val]++;
      if (m[val] == 1) cnt++;
   };
   auto remove = [&](int val) {
      m[val]--;
      if (m[val] == 0) cnt--;
   };
   int l = 0;
   int r = -1;
   vector<int> ans(qq);
   for (int i = 0; i < qq; ++i) {
      while (l < q[i].l) remove(v[l]), l++; 
      while (l > q[i].l) l--, add(v[l]);
      while (r < q[i].r) r++, add(v[r]);
      while (r > q[i].r) remove(v[r]), r--;
      ans[q[i].i] = cnt;
   }
   for (auto x : ans) cout << x << "\n";
}















