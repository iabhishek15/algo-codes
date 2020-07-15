#pragma GCC optimize("Ofast")
#include <bits/stdc++.h> 
using namespace std;

//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;

//template<class T> using oset=tree<T, null_type, less<T>, 
//rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0) 
#define rep(pp,nn) for (int ii = pp; ii < nn; ++ii)
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define type(ade) typeid(ade).name();
#define starting() auto start = high_resolution_clock::now()
#define ending() auto stop = high_resolution_clock::now();\
auto duration = duration_cast<microseconds>(stop - start);\
cerr << "\n" << "\n" << "Execution Time : "<< duration.count()/1000 << " ms" << "\n"

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template <typename T1>
void print_2d_vector(vector<vector<T1>> arr) {
	for (int i = 0; i < (int)arr.size(); ++i) {
		(i == 0)?cerr << "\n[[" : cerr << "\n" << " [";
	    for(int j = 0; j < (int)arr[i].size(); ++j) {
			(j == (int)arr[i].size() - 1) ? cerr << arr[i][j] : cerr << arr[i][j] << "," ;
		}
	    cerr << "]";
	}
	cerr << "]\n";
}
template <typename T1,typename T2>
void print_map(map<T1,T2> m) {
	for(auto ite = m.begin(); ite != m.end(); ++ite){
		cerr << "'" << ite->first << "'"<< " : " << ite->second << "\n";
	}
}

template <typename T1 , typename T2>
void print_map_array(map<T1,vector<T2>> m) {
	for (auto ity = m.begin(); ity != m.end(); ++ity) {
		cerr << "'" << ity->first << "'" << " : " << "[";
        for (int i = 0; i < (int)ity->second.size(); ++i) {
			(i == (int)ity->second.size() - 1) ? cerr << ity->second[i] : cerr << ity->second[i] << ",";
		}
		cerr << "]"<< "\n";
	}
}
template <typename T1, typename T2>
void print_vector_pair(vector<pair<T1,T2>> vp) {
	for (int arrp = 0; arrp< (int)vp.size(); ++arrp){
		cerr << "(" << vp[arrp].first << "," << vp[arrp].second << ")" << "\n" ;
	}
}

string int_to_string(int x) {
    stringstream ss;
	ss << x;
	string ni = ss.str();
	return ni;
}
int string_to_int(string x) {
	int n;
	stringstream s(x);
	s >> n;
	return n;
}

char int_to_char(int a) {
	return a + '0';
}


int64_t power_mod(ll a, ll b, ll mo) {
	ll ans = 1;
	while (b) {
		if(b & 1) {
			ans = (ans % mo * a % mo) % mo;
		}
		a = (a % mo * a % mo) % mo;
		b /= 2;
	}
	return ans;
}
int64_t POW(ll a, ll b) {
	ll ans = 1;
	while (b) {
		if(b & 1) {
			ans = ans * a;
		}
		a = a * a;
		b /= 2;
	}
	return ans;
}

vector<int64_t> INVERSE(int64_t nn, int64_t mo) {
	vector<int64_t> inv(nn + 1);
	vector<int64_t> mul(nn + 1);
	inv[0] = 1;
    inv[1] = 1;
	for (ll i = 2; i <= nn; ++i) {
		inv[i] = (mo - (mo / i) * inv[mo % i] % mo) % mo; 
	}
	mul[0] = 1;
	for (int i = 1; i <= nn; ++i) {
		mul[i] = (mul[i - 1] * inv[i]) % mo;
	}
	return mul;
}

int const r_array = 4;
int const c_array = 4;
void print_2d_array(int arr[r_array][c_array]) {
	//int r =  sizeof(arr)/sizeof(arr[0]); //_countof(arr)
	//int c = sizeof(arr)/(sizeof(int)*r); //_countof(*arr)
	for (int i = 0; i < r_array; ++i) {
		(i == 0)?cerr << "\n[[" : cerr << "\n" << " [";
	    for(int j = 0; j < c_array; ++j) {
			(j == c_array - 1) ? cerr << arr[i][j] : cerr << arr[i][j] << "," ;
		}
	    cerr << "]";
	}
	cerr << "]\n";
}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif


/*********************code starts from here****************************************/



int main() {
	IOS;
	//#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//#endif
	vector<int> a = {1,2,3,4};
	vector<vector<int>> b = {{1,2,3,4,5},
							 {2,3,5,6,7}};
	int aa[4][4] = {{2,2,3,4},{2,23,34,5}};
	map<int,int> m;
	map<int,vector<int>> x;
	vector<pair<int,int>> p;
	for (int i = 0; i < 10; ++i) {
		m[i]++;
		x[i].push_back(i);
		x[i].push_back(i + 100);
		p.push_back({i,i + 10001});
	}	
	print_2d_array(aa);
	print_2d_vector<int>(b);
	print_map<int,int>(m);
	print_map_array<int>(x);
	print_vector_pair<int,int>(p);
	debug(a);
}
