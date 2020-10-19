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
	int n, x;
	cin >> n >> x;
	map<int, int> check;
	int a[n+1] = {0};
	for(int i = 1; i < n; i++){
		int u, v;
		cin >> u >> v;
		a[v] = u;
		check[u]++;
		check[v]++;
	}
	if(n == 1 || check[x] == 1){
		cout << "Ayush" << endl;
	}else{
		x = n-2;
		if(~x&1)
			cout << "Ayush" << endl;
	   else
			cout << "Ashish" << endl;
	}
 	
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
