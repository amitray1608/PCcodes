//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
/*CREDIT : https://www.geeksforgeeks.org/segment-tree-efficient-implementation/
//const ll N = 100005;  
  //ll n;
 //Max size of tree 
//ll tree[4 * N]; 
  
 function to build the tree 
//void build( ll arr[])  
//{  
     insert leaf nodes in tree 
    //for (ll i=0; i<n; i++)     
        //tree[n+i] = arr[i]; 
      
     build the tree by calculating parents 
    //for (ll i = n - 1; i > 0; --i)      
        //tree[i] = tree[i<<1] & tree[i<<1 | 1];     
//} 
  
 function to update a tree node 
//void updateTreeNode(ll p, ll value)  
//{  
     set value at position p 
    //tree[p+n] = value; 
    //p = p+n; 
      
     move upward and update parents 
    //for (ll i=p; i > 1; i >>= 1) 
        //tree[i>>1] = tree[i] & tree[i^1]; 
//} 
  
 function to get sum on interval [l, r) 
//ll query(ll l, ll r)  
//{  
    //ll res = 0; 
      
     loop to find the sum in the range 
    //for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
    //{ 
        //if (l&1)  
            //res += tree[l++]; 
      
        //if (r&1)  
            //res += tree[--r]; 
    //} 
      
    //return res; 
//} 
  */

void solve(){
	int n;
    cin >> n;
    int a[n], odd[n+1]={0}, even[n+1]={0};
	int count = 0;
    for(int &i : a){ 
		cin >> i;
		count++;
		if(i&1){
			odd[count] = odd[count-1]+1;
		}else{
			even[count] = even[count-1]+1;
		}
	}
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        l--, r--;
        //int x = even[r]-even[l], y = odd[r]-odd[l];
        ((a[l]&a[r])&1) ? cout << "ODD\n": cout << "EVEN\n";
        
    }
    
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
	
