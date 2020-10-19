//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
int dx[] = {-1, 1};
int dy[] = {1, -1};
void solve(){
	int n, m;
	cin >> n >> m;
	string s[n];
	for(int i = 0; i < n; i++)
		cin >> s[i];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(s[i][j] == '.'){
				if((i+j)&1)
				s[i][j] = 'B';
				else
				s[i][j] = 'W';
			}
		}
	}
	for(auto i : s){
		cout << i << endl;
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

