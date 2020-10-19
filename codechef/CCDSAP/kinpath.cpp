//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
enum alpha {a, b, c, d, e, f, g, h};
int dx[] = {-1, 0, 1};
int dy[] = {-1, 0, 1};



void solve(){
	string s, t;
	cin >> s >> t;
	pair<int, int>k = {((int)s[0]-'a')+1, (int)s[1]-'0'};
	pair<int, int>w = {((int)t[0]-'a')+1, (int)t[1]-'0'};
	int x = k.first, y = k.second;
	int xx = w.first, yy = w.second;
	cout << max(abs(x-xx), abs(y-yy))<< endl;
	while(true){
		if(x == xx && y == yy) break;
		if(x < xx)
			x++, cout << "R";
		if(x > xx)
			x--, cout << "L";
		if(y > yy)
			y--, cout << "D";
		if(y < yy)
			y++, cout << "U";
		
		cout << endl;
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
