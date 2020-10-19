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
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	int ans = 0;
	string s[n];
	for(int i=0; i < n; i++){
		cin >> s[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c = s[i][j];
			if(c == '.'){
				if(j+1 < m  and s[i][j+1] == '.'){
					ans += min(2*x, y);
					j++;
				}else{
					ans += x;
				}
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
