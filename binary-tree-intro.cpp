#include "bits/stdc++.h"
#include <chrono> 
 
using namespace std;
using namespace std::chrono; 
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
#define gcd(a,b) __gcd(a,b)
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vc vector<char>
#define pb(n) push_back(n)
#define pp pop_back()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define type(a) typeid(a).name();
#define print(arr) cout << "[" ;for(unsigned int i=0;i<(unsigned int) arr.size();i++){ (i==arr.size()-1)?cout << arr[i]:cout << arr[i] << ",";}cout << "]" << endl
#define Arr(arr,l) cout << "[" ;for(unsigned int i=0;i<(unsigned int) l;i++){ (i==l-1)?cout << arr[i]:cout << arr[i] << ",";}cout << "]" << endl
#define console(arr) cout << "["<<endl; for(ll i=0;i<(ll)arr.size();++i){cout << " [";for(ll j=0;j<(ll)arr[i].size();++j){(j==(int)arr[i].size()-1)?cout << arr[i][j]:cout << arr[i][j] << ",";}cout << "]"<<endl;} cout << "]"<<endl
#define starting() auto start = high_resolution_clock::now()
#define ending() auto stop = high_resolution_clock::now();auto duration = duration_cast<microseconds>(stop - start);cout << endl << endl << "Execution Time : "<<duration.count()/1000 << " ms" << endl
 
template <typename T1,typename T2>
void mapped(map<T1,T2>m){for(auto ite=m.begin();ite!=m.end();++ite){cout << "'" << ite->first << "'"<<" : "<<ite->second <<endl;}}
 
template <typename T1 , typename T2>
void mappedArr(map<T1,vector<T2>>m){for(auto ity=m.begin();ity!=m.end();++ity){cout << "'"<< ity->first <<"'"<<" : "<<"[";
for(int i=0;i<(int)ity->second.size();++i){(i==(int)ity->second.size()-1)?cout << ity->second[i]:cout << ity->second[i] << ",";}cout << "]"<<endl;}}
 
string int_to_string(int x){ stringstream ss; ss << x; string ni = ss.str(); return ni;}
int char_to_int(char c){ int n = (int)c - 48; return n; }
int string_to_int(string x){ int n; stringstream s(x); s >> n; return n; }
 
template <typename T1,typename T2>
void ArrPair(vector<pair<T1,T2>>vp){for(int i=0;i<(int)vp.size();++i){
cout << "(" << vp[i].first << "," << vp[i].second << ")"<<endl ;}}
 
const int MOD = 1e9 + 7;
const ll INF = 1e18L + 5;
 
unordered_map<int,int> um;
unordered_set<int> us;
set<int> s;
// v.front() gives the first element of vector 
// v.back()  gives the last element of vector
// insert erase substr
//g++ -o Legendary-Grandmaster Legendary-Grandmaster.cpp&Legendary-Grandmaster.exe 
//cd C:\Users\158si\Desktop\Algorithim\codeForces\elite
// for-bash cd C:/Users/158si/Desktop/Algorithim/codeForces/elite
class bst{
   private:
	struct node{
		int key;
		node* left;
		node* right;
		node* parent;
	};
    node* root;
	public:
	bst(){
		root = NULL;
	}
	node* construct_node(int key,node* ptr){
		node* n = new node;
		n->key = key;
		n->right = NULL;
		n->left = NULL;
		n->parent = ptr;
		return n;
	}
	void addleafchecking(int key){
		addleaf(key,root);
	}
	void addleaf(int key,node* ptr){
		//ptr = root;
		if(root==NULL){
			root = construct_node(key,ptr); 
		}else{
			if(key<ptr->key){
				if(ptr->left==NULL){
					ptr->left = construct_node(key,ptr);
				}else{
					addleaf(key,ptr->left);
				}
			}else if(key>ptr->key){
				if(ptr->right==NULL){
					ptr->right = construct_node(key,ptr);
				}else{
					addleaf(key,ptr->right);
				}
			}else{
				cout << "The number is laready present in the tree";
			}
			
		}	
	}
	void printAcc(){
	    if(root!=NULL){
	 	  printA(root);
	    }else{
		  cout << "Tree is empty\n";
		} 
	}
	void printA(node* ptr){
		if(ptr->left!=NULL){
			printA(ptr->left);
		}
		cout << ptr->key << " ";
		if(ptr->right!=NULL){
			printA(ptr->right);
		}
		
	}
	void printChilds(int key){
	    printChild(key,root);
	}
	int value(node* ptr){
		return ptr->key;
	}
	node* checking(int key){
		return traversingtree(key,root);
	}
	node* traversingtree(int key,node* ptr){
       	if(ptr->key==key){
			return ptr;
		}else{ 
			if(key<ptr->key){
			   if(ptr->left!=NULL){
				 return traversingtree(key,ptr->left);
			   }else{
				   return NULL;
			   }
			}else if(key>ptr->key){
			    if(ptr->right!=NULL){
				  return  traversingtree(key,ptr->right);
			    }else{
					return NULL;
				}
		    }
		}
		return NULL;
	}
	void finding(int key){
	    node* n = checking(key);
	    if(n!=NULL){
			cout << "Present\n";
		}else{
			cout << "Absent\n";
		}
	}
  void deleteNode(int key){
	  del(key);
  }
  
 
  node* lastRight(node* ptr){
	  return checkLeft(ptr->right);
  }
  node* checkLeft(node* ptr){
	  if(ptr->left==NULL){
		  return ptr;
	  }else{
		  return checkLeft(ptr->left);
	  }
  }
  
  void printChild(int key ,node* ptr){
		cout << key << "\n";
		ptr = checking(key);
	if(ptr!=NULL){	
		//cout << ptr;
		if(ptr->left!=NULL){
			cout << "Left is " << value(ptr->left);
		}else{
			cout << "Left is null";
		}
		cout << "\n";
		if(ptr->right!=NULL){
			cout << "Right is " << value(ptr->right);
		}else{
			cout << "Right is null";
		}
		cout << "\n";
	  }else{
		  cout << "It is not present\n";
	  }
   }
   void printParent(int key){
	    parentNode(key,root);
   }
   void parentNode(int n,node* ptr){
	  if(root->key==n){
		  cout << "NULL";
		}else{
			node* w = checking(n);
			node* k = w->parent;
			cout << k->key << endl;
		}
   }
   node* getParent(int key){
	   return parentcheck(key,root);
   }
   node* parentcheck(int n,node* ptr){
	  if(root->key==n){
		  return NULL;
		}else{
			node* w = checking(n);
			node* k = w->parent;
			return k;
		}
   }
    void del(int key){
	  node* ptr;
	  ptr = checking(key);
	  node* n = getParent(key);
	  if(n==NULL){
		  root= NULL;
	  }else if(ptr==NULL){
		  cout << "It is not present";
	  }else{
		  if(ptr->left==NULL && ptr->right==NULL){
			  ptr->parent = NULL;
			  ptr = NULL;
		  }else if(ptr->left==NULL){
			  if(key==value(n->left)){
				n->left = ptr->right;  
			  }else if(key==value(n->right)){
				 n->right = ptr->right;
			  }
			  ptr->right->parent = n;
		  }else  if(ptr->right==NULL){
			 if(key==value(n->left)){
				n->left = ptr->left;  
			  }else if(key==value(n->right)){
				 n->right = ptr->left;
			  }
			  ptr->left->parent = n;
		  }else{
			   node* w = lastRight(ptr);
			   ptr->key = value(w);
			if(w->left==NULL && w->right==NULL){
			  ptr = NULL;
			  ptr->parent = NULL;
		    }else{
				node* p = getParent(w->key);
				 p->left = w->right;
				 p->left->parent = p;
				 p->parent = NULL;
		     }
		  }
	  }
	  
  }	
};

int main(){
  IOS;
  int words[10] = {1,5,46,32,54,48,62,52,56,72};
  bst tree;
  //tree.printAcc();
  for(int i=0;i<10;++i){
	  tree.addleafchecking(words[i]);
  }
  //tree.printAcc();
  tree.deleteNode(5);
 // tree.printAcc();
  //for(int i=0;i<8;++i){
  
   //   tree.printChilds(words[i]);
 // }
  tree.printParent(46);
 //  tree.printChilds(48);
  // tree.printChilds(5);
  //for(int i=0;i<8;++i){
//	  tree.printParent(words[i]);
  //}
  return 0;
}
  

 
