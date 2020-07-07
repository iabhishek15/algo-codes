pair<int,int> euclead(int a, int b) {
    if (a == 0) {
		return {0,1};
	}
	pair<int,int> p = euclead(b % a,a);
	int x1 = p.first;
	int y1 = p.second;
	return {y1 - (b / a) * x1 ,x1};
} 
 
int main() {
	pair<int,int> a = euclead(30,20);
	cout << a.first << " " << a.second ;
}
 
