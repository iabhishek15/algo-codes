#include "bits/stdc++.h"
using namespace std;

//function to merge two array
vector<int> merging(vector<int> a,vector<int> b){	
	int x = (int)a.size() + (int)b.size();
	vector<int> v(x);
	size_t p = 0;
size_t q = 0;
size_t i = 0;

while(p < a.size() && q < b.size()) {
    if(a[p] < b[q]){
        v[i++] = a[p++];
    }else{
        v[i++] = b[q++];
    }
}

while(p < a.size()) {
    v[i++] = a[p++];
}

while(q < b.size()) {
    v[i++] = b[q++];
}
	return v;
}


//splitting the array and then merging the array
vector<int> mergeSort(vector<int> k){
   int x = (int)k.size();
   if(x<2){
	   return k;
   }
   vector<int> a(k.begin(),k.begin()+(x/2));
   vector<int> b(k.begin()+(x/2),k.end());
   return merging(mergeSort(a),mergeSort(b));
}


int main(){
	vector<int> v = {3,5,34,11,32,7,35,54,67,89,23,4,3};
	//calling the merge function
    vector<int> b = mergeSort(v);
    for(int i=0;i<(int)b.size();++i){
		cout << b[i] << "\n";
	}
  return 0;
}






















