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
	int n, m;
		cin >> m;
		n = m+1;
	int adj[2*n];
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		a[x] i;
	}
		int a[], b[], c[] //let these 3 be the traversal array
		int ans = 0;
		for(int i = 0; i < n; i++){
			int tmp[3];
			tmp[0] = a[i];
			tmp[1] = b[i];
			tmp[2] = c[i];
			sort(tmp, tmp+3);
			ans = (ans + tmp[1])%1000000007;
		}
		cout << ans << endl;
	}
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
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
