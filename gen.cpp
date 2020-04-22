//generating a random sequence of distinct elements
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
//to generate a random number in a range
ll rand(ll a, ll b) {
	return a + rand() % (b - a + 1);
}
//string s = "abcdefghijklmnopqrstuvwxyz";
int main(int argc, char* argv[]) {
	srand(atoi(argv[1])); //atoi(s) converts the array of chars into int
	int n = rand(1,100);
	cout << n << endl;
	for (int i = 0; i < n; ++i) {
		int m = rand(1,100000);
		int k = rand(1,100000);
		cout << m << " " << k << endl;
	}
}







//int main(int argc, char* argv[]) {
	//srand(atoi(argv[1])); //atoi(s) converts the array of chars into int
	//int n = rand(2,1000);
	//printf("%d\n",n);
	//set<int> used;
	//for (int i = 0; i < n; ++i) {
		//int x;
		//do {
			//x = rand(1,1000);
		//}while(used.count(x));
		//printf("%d ",x);
		//used.insert(x);
	//}
	//puts("");
//}
