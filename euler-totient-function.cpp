// We can avoid floating point calculations in above method.The idea is to count all prime factors and their multiples and 
// subtract this count from n to get the totient function value (Prime factors and multiples of prime factors won’t have gcd as 1)

//1) Initialize result as n//
//2) Consider every number 'p' (where 'p' varies from 2 to ?n). 
//   If p divides n, then do following
//    a) Subtract all multiples of p from 1 to n [all multiples of p
//       will have gcd more than 1 (at least p) with n]
//    b) Update n by repeatedly dividing it by p.
// 3) If the reduced n is more than 1, then remove all multiples
//    of n from result.

for (ll i = 2; i * i <= n; ++i){
	if (n % i == 0) {
		ans -= ans/i;
		while (n % i == 0) {
			n /= i;
		}
  }
}
if (n > 1) {
	ans -= ans/n;
}


//my way
for (ll i = 2; i * i <= b; ++i){
			if (b % i == 0) {
				if (isprime(i)) {
					ans1 *= (i - 1);
					ans1 /= i;
				}
				if (i * i != b && isprime(b/i)) {
					ans1 *= (b/i - 1);
					ans1 /= b/i;
				}
			}
		}
		if (isprime(b)) {
			ans1 /= b;
			ans1 *= (b - 1);
		}
