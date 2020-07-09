ll power_ch(ll a, ll b, ll mo) {
	ll ans = 1;
	while (b) {
		if(b & 1) {
			ans = (ans * a) % mo;
		}
		a = (a * a) % mo;
		b /= 2;
	}
	return ans;
}         
int main() {
	ll n;
	cin >> n;
	ll x = 0;
	for (ll i = 2; i < 22; ++i) {
		if (i % n != 0) {
			x = i;
			break;
		}
	}
	if (power_ch(x,n - 1,n) % n == 1) {
		cout << 0;
	}else {
		cout << 1;
	}
}
  
