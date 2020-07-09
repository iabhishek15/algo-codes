
Conditions: 
1) MOD is a prime number 
1) you should be able to calculate C(ni, ki) % MOD, where (0 ≤ ni, ki < MOD). // means a1[i] >= a2[i] else 0
//when mod is prime

Advices:
1) this theorem is very useful in case N ≥ MOD, otherwise it's better to use formula C(N, K) = N! / ((N - K)! * K!) 
2) If N ≥ MOD then N! % MOD = 0, when C(N, K) % MOD is not necessary equals to 0.

//1)  
vector<int> get_representation(int n,int mod) {
	vector<int> res;
	while (n) {
		res.push_back(n % mod);
		n /= mod;
	}
	return res;
}
  
int main() {
	ll n, k, mod;
	cin >> n >>  k >> mod;
	vector<ll> comb(n + 1);
	comb[0] = 1;
	for (ll i = 1; i <= n; ++i) {
		comb[i] = (comb[i - 1] * i) % mod;
	}
	vector<ll> inv(n + 1);
	inv[0] = 1;
	inv[1] = 1;
	for (ll i = 2; i <= n; ++i) {
		inv[i] = (mod - (mod/i) * inv[mod % i] % mod) % mod;
	}
	vector<ll> mul(n + 1);
	mul[0] = 1;
	for (ll i = 1; i <= n; ++i) {
		mul[i] = (mul[i- 1] * inv[i]) % mod;
	}
	vector<int> a1 = get_representation(n,mod);
	vector<int> a2 = get_representation(k,mod);
	ll ans = 1;
	for (int i = 0; i < (int)a2.size(); ++i) {
		if (a2[i] > a1[i]) {
			cout << 0;
			return 0;
		} 
		ans = (ans % mod * ((comb[a1[i]] * mul[a2[i]]) % mod * mul[a1[i] - a2[i]] % mod) % mod) % mod;
	}
	cout << ans;
}




2)

#include <bits/stdc++.h> 
using namespace std;

int binpow(int a, int n,int MOD) {
    long long res = 1;
    while (n > 0) {
        if (n % 2 != 0) {
            res = (res * a) % MOD;
        }
        a = ((long long)a * a) % MOD;
        n /= 2;
    }
    return (int)res;
}

vector<int> getRepresentation(int N, int MOD) {
    vector<int> res;
    while (N > 0) {
        res.push_back(N % MOD);
        N /= MOD;
    }
    return res;
}
int C(int N, int K, int MOD,vector<int> fact) {
    if (K > N) {
        return 0;
    }
    return (((fact[N] * binpow(fact[N - K], MOD - 2,MOD))% MOD) * binpow(fact[K], MOD - 2,MOD)) % MOD;
}


int main() {
	int N, K, MOD;
	cin >> N >> K >> MOD;
	vector<int> fact(MOD + 1);
	fact[0] = 1;
	for (int i = 1; i < MOD; ++i) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	vector<int> n = getRepresentation(N,MOD);
	vector<int> k = getRepresentation(K,MOD);        
	long long res = 1;
	for (int i = 0; i <(int) k.size(); ++i) {
		res = (res * C(n[i], k[i],MOD,fact)) % MOD;
	}
	cout << res;
}

