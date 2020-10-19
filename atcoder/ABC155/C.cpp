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
	int n;
	cin >> n;
	string s[n];
	int count = 0;
	map<string , int>c;
	vector<string>v;
	for(int i = 0; i< n; i++){
		cin >> s[i];
		c[s[i]]++;
		count = max(count, c[s[i]]);
	}
	for(auto x : c){
		if(x.second == count)
		v.push_back(x.first);	
	}
	sort(v.begin(), v.end());
	for(auto cc : v)
		cout << cc << endl;
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
