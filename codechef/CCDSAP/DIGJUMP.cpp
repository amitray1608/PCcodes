//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vecor<vector<pair<int, int>>>adj;
int n, s, d;

void solve(){
	string s;
	cin >> s;
	n = (int)s.length();
	s = s[0], d = s[n-1];
	for(int 	i = 0; i < n; i++){
		if(i == 0){
			adj[i].push_back(make_pair(i+1, (int)s[i]-'0'));
			adj[i+1].push_back(make_pair(i-1, (int)s[i+1]-'0'));
		}else if(i == n-1){
			adj[i].push_back(make_pair(i-1, (int)s[i]-'0'));
			adj[i-1].push_back(make_pair(i+1, (int)s[i-1]-'0'));
		}else{
			adj[i].push_back(make_pair(i+1, (int)s[i]-'0'));
			adj[i+1].push_back(make_pair(i-1, (int)s[i+1]-'0'));
			adj[i].push_back(make_pair(i-1, (int)s[i]-'0'));
			adj[i-1].push_back(make_pair(i+1, (int)s[i-1]-'0'));
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
