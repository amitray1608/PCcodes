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
	cin >> n >> m;
	int s[m], c[m];
	for(int i = 0; i < m; i++)
		cin >> s[i] >> c[i];
	
	int vis[n] = {0} ;
	int a[n] = {0};
	for(int i= 0; i < m; i++){
		if(s[i] != 1){
			if(vis[s[i]-1] == 0){
				a[s[i]-1] = c[i];
				vis[s[i]-1] = 1;
			}else
				a[s[i]-1] = min(c[i], a[s[i]-1]);
		}	
	}
		
	for(int i= 0; i < m; i++){
		if(s[i] == 1){
			if(vis[0] == 0){
				a[0] = c[i];
				vis[0] = 1;
			}else{
				if(c[i] == 0) continue;
				else
					a[0] = min(c[i], a[0]);
			}
		}
	}
	if(n == 1){
		for(int i = 0; i <m; i++){
		if(s[i] == 1){	
		if(vis[0] == 0){
				a[0] = c[i];
				vis[0] = 1;
		}else{
				a[0] = min(c[i], a[0]);
			}
		}	
	}
		cout << a[0];
	}else{
	if(a[0] == 0)
		cout << -1;
	else{
		for(int &i : a)
			cout << i ;
	}
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
