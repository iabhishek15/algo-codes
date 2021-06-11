bool miller_rabin(int64_t N) {
  if (N < 2) {
    return false;
  }
  for (int p : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}) {
    if (N % p == 0) {
      return N == p;
    }
  }
  int R = __builtin_ctz(N - 1);
  int64_t d = (N - 1) << R;
  for (int  a : {2, 7, 61}) {
    int64_t x = power_mod(a % N, d, N);
    if (x <= 1 || x == N - 1) {
      continue;
    }
    for (int i = 0; i < R - 1 && x != N - 1; i++) {
      x = x * x % N;
    }
    if (x != N - 1) {
      return false;
    }
  }
  return true;
}

