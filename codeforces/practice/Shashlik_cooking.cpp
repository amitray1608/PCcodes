//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
void solve(){
	int n , k ;
	cin >> n >> k ;
	int	l = 2*k + 1 ;  
	vector<int> v ;
	if(n%l > 0 && n%l < k+1){
		for(int i = 1 ; i <= n ; i+=l) v.push_back(i) ;
	}else{
		for(int i = k+1 ; i <= n ; i+= l) v.push_back(i) ;
	}
	cout << v.size() << endl ;
	for(auto i : v) cout << i <<" ";
		
		cout << endl ;
}

int main(){
	#ifndef RAY
		freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		//cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
	
