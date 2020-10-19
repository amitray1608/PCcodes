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
	int h, w;
	cin >> h >> w;
	ll v[h][w];
	for(int i = 0; i<h; i++){
		for(int j = 0; j <w; j++)
			cin >> v[i][j];
	}
	
	for(int i = h-2; i >= 0; i--){
		for(int j = 0; j < w; j++){
			if(j == 0){
				v[i][j]= max(v[i][j]+v[i+1][j], v[i][j]+v[i+1][j+1]);
			}else if(j == w-1){
				v[i][j] = max(v[i][j]+v[i+1][j], v[i][j]+v[i+1][j-1]);
			}else{
				v[i][j] = max(v[i][j]+v[i+1][j], max(v[i+1][j+1]+v[i][j], v[i+1][j-1]+v[i][j]));
			}
		}	
	}
	//~ for(int i : dp) cout << i << " ";
		//~ cout << endl;
		int ans = 0;
	for(int i = 0; i <w; i++){
		//cout << v[0][i] << " ";
		ans = max(ans, (int)v[0][i]);
	}
	//cout << endl;
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
