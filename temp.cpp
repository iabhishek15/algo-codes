#include "bits/stdc++.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(ii,nn) for (int ii = 0; ii < nn; ++ii)
#define gcd(ade,bde) __gcd(ade,bde)
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vc vector<char>
#define pb(ade) push_back(ade)
#define pp pop_back()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define type(ade) typeid(ade).name();
#define starting() auto start = high_resolution_clock::now()
#define ending() auto stop = high_resolution_clock::now();\
auto duration = duration_cast<microseconds>(stop - start);\
cerr << "\n" << "\n" << "Execution Time : "<< duration.count()/1000 << " ms" << "\n"

template <typename T1>
void print(vector<T1> arr) {
	int l = (int)arr.size();
	cerr << "[" ;
	for(int i = 0; i < l; i++) {
		(i == l - 1) ? cerr << arr[i] : cerr << arr[i] << "," ;
	}
	cerr << "]" << "\n";
}

template <typename T1>
void printArr(int arr[], int l) {
	cerr << "[" ;
	for (int i = 0; i < (int)l; i++) {
		(i == l-1) ? cerr << arr[i] : cerr << arr[i] << "," ;
	}
	cerr << "]" << "\n";
}

template <typename T1>
void console(vector<vector<T1>> arr) {
	for (int i = 0; i < (int)arr.size(); ++i) {
		cerr << "\n" << " [" ;
	    for(int j = 0; j < (int)arr[i].size(); ++j) {
			(j == (int)arr[i].size() - 1) ? cerr << arr[i][j] : cerr << arr[i][j] << "," ;
		}
	    cerr << "]";
	}
	cerr << "\n";
}
template <typename T1,typename T2>
void mapped(map<T1,T2> m) {
	for(auto ite = m.begin(); ite != m.end(); ++ite){
		cerr << "'" << ite->first << "'"<< " : " << ite->second << "\n";
	}
}

template <typename T1 , typename T2>
void mappedArr(map<T1,vector<T2>> m) {
	for (auto ity = m.begin(); ity != m.end(); ++ity) {
		cerr << "'" << ity->first << "'" << " : " << "[";
        for (int i = 0; i < (int)ity->second.size(); ++i) {
			(i == (int)ity->second.size() - 1) ? cerr << ity->second[i] : cerr << ity->second[i] << ",";
		}
		cerr << "]"<< "\n";
	}
}

string int_to_string(int x) {
    stringstream ss;
	ss << x;
	string ni = ss.str();
	return ni;
}
int char_to_int(char c) {
	int n = (int)c - 48;
	return n;
}
int string_to_int(string x) {
	int n;
	stringstream s(x);
	s >> n;
	return n;
}

template <typename T1, typename T2>
void vectPair(vector<pair<T1,T2>> vp) {
	for (int arrp = 0; arrp< (int)vp.size(); ++arrp){
		cerr << "(" << vp[arrp].first << "," << vp[arrp].second << ")" << "\n" ;
	}
}

//unordered_map<int,int> um;
//unordered_set<int> us;
//set<int> s;
// v.front() gives the first element of vector
// v.back()  gives the last element of vector
// insert erase substr
//g++ -o Legendary-Grandmaster Legendary-Grandmaster.cpp&Legendary-Grandmaster.exe
//cd C:\Users\158si\Desktop\Algorithim\codeForces\elite
// for-bash cd C:/Users/158si/Desktop/Algorithim/codeForces/elite
//memset(arr,element,sizeofarray);//Converts the value ch to unsigned char and copies it
// into each of the first n characters of the object pointed to by str[].
//g++ -o impulse.exe impulse.cpp
//puts

typedef long long ll;

ll power (ll a, ll n) {
	ll ans = 1;
	for (ll i = 0; pow(2,i) <= n; ++i) {
		if ((n >> i) & 1) {
			ans *= a;
		}
		a = a * a;
	}
	return ans;
}

void inverse(vector<ll>& v, ll w, ll p) {
	v[1] = 1;
	for (ll i = 2; i < w; ++i) {
		v[i] = (p - (p/i) * v[p % i] % p) % p;
	}
}

ll gcd(ll a, ll b) {
	if (b == 0) {
	    return a;	
	}
	return gcd(b,a % b);
}

ll lcm(ll a, ll b) {
	ll ans = a * b / gcd(a,b);
	return ans;
}
	
const ll INF = 1e18L + 5;
const int MOD = 1e9 + 7;


//vectPair<type>(v)         //vector<pair> 
//mappedArr<type,type>(m)   //map<array>
//mapped<type,type>(m)      // map
//printArr<type>(arr,len)   //arry
//print<type>(vect)         //1D vector 
//console<type>(arr)        //2D vector

/**************************/


//some usefull links
//https://csacademy.com/app/graph_editor/    //for visualization of graph and  trees
//https://www.desmos.com/calculator          //for lines and graphs in a plane
//https://www.wolframalpha.com/              //for maths scientific calculation
//https://oeis.org/                          //another math scientific calculation webite
//https://codeforces.com/blog/entry/70330    //2d visualizer

///things to look for
// * int overflow, array bounds
// * special cases (n=1?)
// * analyze the time complexity properly
// * read the question properly and check for constrains
// * while using global variable make sure to re-initialize it


int main() {
	IOS;
	//#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//#endif
	
	
	return 0;
}


