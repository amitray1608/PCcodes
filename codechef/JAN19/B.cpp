//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
int up, down, lef, righ;
void assign(int i, int j){
	up = i-1;
	down = i+1;
	lef = j-1;
	righ = j+1;
}
void solve(){
	int n, m;
	cin >> n >> m;
	int a[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cin >> a[i][j];
	}
	ll ans = n*m;
	int flag;
	for(int i = 1; i < n-1; i++){
		for(int j = 1; j < m-1; j++){
			flag = 1;
			assign(i, j);
			while(flag && up >= 0 && down < n && lef>= 0 && righ < m){
				if(a[up][j] == a[down][j] && a[i][lef] == a[i][righ])
					ans++;
				else flag = 0;
				
				up--, lef--, down++, righ++;
			}
		}
	}
	cout << ans << endl;
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





