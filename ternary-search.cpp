problem : https://codeforces.com/problemset/problem/439/D

for getting the minimum value

int l = 1;
int r = 1e9 + 7;
while (l < r) {
  int m1 = l + (r - l) / 3;
  int m2 = r - (r - l) / 3;
  int val1 = 0;
  int val2 = 0;
  for (int i = 0; i < n; ++i) {
    val1 += max(m1 - a[i], 0LL);
    val2 += max(m2 - a[i], 0LL);
  }
  for (int i = 0; i < m; ++i) {
    val1 += max(b[i] - m1, 0LL);
    val2 += max(b[i] - m2, 0LL);
  }
  if (val1 <= val2) {
    r = m2 - 1;
  }else {
    l = m1 + 1;
  }
}


for maximum value 

int l = 0;
int r = n - 1;
while (l < r) {
  int m1 = l + (r - l) / 3;
  int m2 = r - (r - l) / 3;
  if (v[m1] >= v[m2]) {
    r = m2 - 1;
  }else {
    l = m1 + 1;
  }
}


//here we can see that the way of doing both the things are same







