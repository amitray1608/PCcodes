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
	string s;
	cin >> s;
	int g[6][3] = {0};
	g[1][0] = 1;
	g[1][1] = 2;
	g[2][0] = 3;
	g[2][1] = 2;
	g[3][0] = 4;
	g[3][1] = 2;
	g[4][1] = 2;
	g[4][0] = 5;
	g[5][1] = 2;
	g[5][0] = 1;
	int pos = 1;
	string ss = "";
	for(char c : s){
		if(c == '1')
			pos = g[pos][1];
		else
			pos = g[pos][0];
	}
	if(pos == 5)
		cout << "YES\n";
	else
		cout << "NO\n";
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
