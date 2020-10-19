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
	int N;
	cin >> N;
	N--;
	int r = 1, c = 1;
	vector<pair<int, int>>res;
	res.push_back({1, 1});
	while (r <= N) {
	  N -= r;
	  res.push_back({r + 1, c + 1});
	  r++;
	}
	while (N--) {
	  res.push_back({r, 1});
	  r++;
	}
	for(auto it : res)
	cout << it.first << " " << it.second << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 1;
		cin >> t;
		while(t--){
			cout << "Case #" << tt++ << ": " << endl;
			solve();
		}
	return 0;
}	
