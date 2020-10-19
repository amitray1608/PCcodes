//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e8 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
	int n, m;
	cin >> n >> m;
	int a[n][m], row[n] = {0}, col[m] = {0};
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			if(a[i][j] == 1){
				row[i] = 1;
				col[j] = 1;
				
			}
		}
	int count = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(row[i] or col[j]) continue;
			count++;
			row[i] = 1;
			col[j] = 1;
		}
	}
	if(~count&1)
		cout << "Vivek" << endl;
	else
		cout << "Ashish" << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
		cin >> t;
		while(t--){
			//tt++;
			//cout << "Case " << tt << ": ";
			solve();
		}
	return 0;
}
