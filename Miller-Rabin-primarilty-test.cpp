
uint64_t modmul(uint64_t a, uint64_t b, uint64_t mod){
  uint64_t res = 0;
  a %= mod;
  while (b > 0){
    if (b & 1)
      res = (res + a) % mod;
    a = (2 * a) % mod;
    b /= 2LL;
  }
  return res % mod;
}

uint64_t binpower(uint64_t base, uint64_t e, uint64_t mod) {
  uint64_t result = 1;
  base %= mod;
  while (e) {
    if (e & 1)
      result = modmul(result, base, mod);
    base = modmul(base, base, mod);
    e >>= 1;
  }
  return result;
}

bool check_composite(uint64_t N, uint64_t A, uint64_t D, int R) {
  uint64_t x = binpower(A, D, N);
  if (x == 1 || x == N - 1) {
    return false;
  }
  for (int r = 1; r < R; r++) {
    x = modmul(x, x, N);
    if (x == N - 1) {
      return false;
    }
  }
  return true;
};


bool MillerRabin(uint64_t N) {
  if (N < 2) {
    return false;
  }
  int64_t D = N - 1;
  int R = 0;
  while ((D & 1) == 0) {
    D >>= 1;
    R++;
  }
  for (uint64_t A : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (N == A) {
      return true;
    }
    if (check_composite(N, A, D, R)) {
      return false;
    }
  }
  return true;
}
