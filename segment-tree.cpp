#include <bits/stdc++.h> 
using namespace std;


int const nax = 2e5 + 11;
int n; 
long long v[nax];
long long seg[nax * 4];

//for sum

void build_sum(int start = 1, int end = n, int index = 1) {
  if (start == end) {
    seg[index] = v[start]; 
    return ;
  }
  int mid = (start + end) / 2;
  build_sum(start, mid, index * 2);
  build_sum(mid + 1,end, index * 2 + 1);
  
  seg[index] = seg[index * 2] + seg[index * 2 + 1];
}
long long query_sum(int x, int y, int start = 1, int end = n, int index = 1) {
  if ((start >= x) &&  (end <= y)) {
    return seg[index];
  }
  if ((y < start) || (x > end)) {
    return 0;
  } 
  int mid = (start + end) / 2;
  return query_sum(x, y, start, mid, index * 2) + query_sum(x, y, mid + 1, end, index * 2 + 1);
}

void update_sum(int given_index, long long value, int start = 1, int end = n, int index = 1) {
  if (start == end) {
    seg[index] = value;
    return ;
  }
  int mid = (start + end) / 2;
  if (given_index <= mid) {
    update_sum(given_index, value, start, mid, index * 2);
  }else {
    update_sum(given_index, value, mid + 1, end, index * 2 + 1);
  }
  seg[index] = seg[2 * index] + seg[2 * index + 1];
}


//for min

void build_min(int start = 1, int end = n, int index = 1) {
  if (start == end) {
    seg[index] = v[start]; 
    return ;
  }
  int mid = (start + end) / 2;
  build_min(start, mid, index * 2);
  build_min(mid + 1,end, index * 2 + 1);
  seg[index] = min(seg[index * 2], seg[index * 2 + 1]);
}

long long query_min(int x, int y, int start = 1, int end = n, int index = 1) {
  if ((start >= x) &&  (end <= y)) {
    return seg[index];
  }
  if ((y < start) || (x > end)) {
    return 1e18 + 17;
  } 
  int mid = (start + end) / 2;
  return min(query_min(x, y, start, mid, index * 2), query_min(x, y, mid + 1, end, index * 2 + 1));
}

void update_min(int given_index, long long value, int start = 1, int end = n, int index = 1) {
  if (start == end) {
    seg[index] = value;
    return ;
  }
  int mid = (start + end) / 2;
  if (given_index <= mid) {
    update_min(given_index, value, start, mid, index * 2);
  }else {
    update_min(given_index, value, mid + 1, end, index * 2 + 1);
  }
  seg[index] = min(seg[index * 2], seg[index * 2 + 1]);
}




//for max
void build_max(int start = 1, int end = n, int index = 1) {
  if (start == end) {
    seg[index] = v[start]; 
    return ;
  }
  int mid = (start + end) / 2;
  build_max(start, mid, index * 2);
  build_max(mid + 1,end, index * 2 + 1);
  
  seg[index] = max(seg[index * 2], seg[index * 2 + 1]);
}

long long query_max(int x, int y, int start = 1, int end = n, int index = 1) {
  if ((start >= x) &&  (end <= y)) {
    return seg[index];
  }
  if ((y < start) || (x > end)) {
    return -1e18 - 7;
  } 
  int mid = (start + end) / 2;
  return max(query_max(x, y, start, mid, index * 2), query_max(x, y, mid + 1, end, index * 2 + 1));
}

void update_max(int given_index, long long value, int start = 1, int end = n, int index = 1) {
  if (start == end) {
    seg[index] = value;
    return ;
  }
  int mid = (start + end) / 2;
  if (given_index <= mid) {
    update_max(given_index, value, start, mid, index * 2);
  }else {
    update_max(given_index, value, mid + 1, end, index * 2 + 1);
  }
  seg[index] = max(seg[index * 2], seg[index * 2 + 1]);
}









