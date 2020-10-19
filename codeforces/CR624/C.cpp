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
	int n, m;
		cin >> n >> m;
	string s;
		cin >> s;
	int p[m];
	for(int &i : p) cin >> i;
		int pref[n];
		for(int i=0;i<n;i++) pref[i] = 0;
		int vis[26];
		for(int i=0; i<26; i++) vis[i]=0;
		for(int i=0; i<m; i++)
		pref[p[i]-1] += 1;
		pref[n-1] = 1;
		for(int i = n-2; i>=0; i--)
		pref[i] += pref[i+1];
		for(int i=0;i <n; i++){
			int pos = s[i]-'a';
			vis[pos] += pref[i];
		}
		for(int i=0; i<26; i++) cout << vis[i] <<" ";
	cout << endl;
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
