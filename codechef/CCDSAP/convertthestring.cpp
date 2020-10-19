//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
int siz = 1e8+1;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int fre[26] = {0}, freb[26] = {0};
	for(int i = 0; i < n; i++)
		fre[a[i]-'a']  = 1, freb[b[i]-'a'] = 1;
	for(int i = 0; i < 26; i++){
		if(freb[i]){
			if(fre[i] != 1){
				cout << -1 << endl;
				return;
			}
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
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
