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
	string s, a;
		cin >> s;
	int count = 0;//freq[28] = {0}, not_e = 0, alpha = -1;
	vector<int>vis(n, 0);
	int l = 0, r = n - 1;
	if(n == 1){
		cout << "YES\n" << 0 << endl;
		return;
	}
	while(l+1 < r){
		if(s[l] != s[r]){
			if(vis[l] && vis[r]){
				cout << "NO" << endl;
				return;
			}
			if(!vis[l] and !vis[l+1] and s[l+1] == s[r]){
				swap(s[l], s[l+1]);
				count++;
				vis[l] = vis[l+1]= 1;
			}
			else if(!vis[r] and !vis[r-1] and s[l] == s[r-1]){
				swap(s[r], s[r-1]);
				count++;
				vis[r-1] = vis[r] = 1;
			}
		}
		l++;
		r--;
	}
	a = s;
	reverse(a.begin(), a.end());
	if(a != s)
		cout << "NO\n";
	else
		cout << "YES\n" << count << endl;
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
