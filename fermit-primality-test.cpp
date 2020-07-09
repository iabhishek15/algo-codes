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
	//by this we can only proof than the number is composite we cannot say about the prime
	//1105 fails , this may be because i am doing the modulas operation
	ll n;
	cin >> n;
	ll x = 0;
	for (ll i = 2; i < 22; ++i) { //22  is used since we can go more than 21 to found a non divisor of number
		if (i % n != 0) {   //since 21! is more than 2^18 , so we will get non divisor quickly
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
  
