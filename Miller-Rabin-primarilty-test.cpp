#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int k = 100;

ll modmul(ll a, ll b, ll mod){
    ll res = 0;
    a %= mod;
    while (b > 0){
        if (b & 1)
            res = (res + a) % mod;
        a = (2 * a) % mod;
        b /= 2LL;
    }
    return res % mod;
}
ll mpow(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0){
        if (exp & 1)
            res = modmul(res, base, mod);
        base = modmul(base, base, mod);
        exp /= 2LL;
    }
    return res % mod;
}
bool millerTest(ll n, ll d) {
    ll a = 2 + rand() % (n - 4);
    ll x = mpow(a, d, n);
    if (x == 1 || x == n - 1)
        return true;
    while (d != n - 1){
        x = modmul(x, x, n);
        d *= 2LL;
        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
    }
    return false;
}
bool is_prime(ll n) {
    if (n < 2)
        return false;
    if (n < 4)
        return true;
    if (n % 2LL == 0)
        return false;
    ll d = n - 1;
    while (d % 2LL == 0)
        d /= 2LL;
    for (int i = 0; i < k; i++) {
        if(!millerTest(n, d))
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        if (is_prime(n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
