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
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int, int >>a, b;
	for(int i = 0; i < k; i++){
		int x, y;
		cin >> x >> y;
		a.push_back(make_pair(x, y));
	}
	for(int i = 0; i < k; i++){
		int x, y;
		cin >> x >> y;
		b.push_back(make_pair(x, y));
	}
	cout << (n+m+(n*m)) - 2<< endl;
	for(int i = 1; i < n; i++) {
			cout << 'U';
	}
	for(int i = 1; i < m; i++) {
		cout << 'L';
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < m; j++) {
			if(i&1) {
				cout << 'R';
			}else
				cout << 'L';
		}
		cout << 'D';
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
