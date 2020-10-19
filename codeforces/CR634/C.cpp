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
	int a[n];
	int fre[n+1]={0}	;
	set<int>s;
	for(int &i : a)
		cin >> i, fre[i]++, s.insert(i);
	int maxi = *max_element(fre, fre+n+1);
	int ans = max(min((int)s.size()-1, maxi), min(maxi-1, (int)s.size()));
	cout << ans << endl;
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
