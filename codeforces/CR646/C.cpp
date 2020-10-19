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
	vector<int>a(n);
	for(int &i : a) cin >> i;
	//cout << ans << endl;
	sort(a.begin(), a.end());
	int mini = INT_MAX;
	for(int i = 0; i < n; i++){
		int x = a[i] ^ a[0];
		if(x == 0) continue;
		vector<int>v;
		for(int j = 0; j < n; j++){
			v.push_back(a[j]^x);
		}
		sort(v.begin(), v.end());
		if(v == a)
			mini = min(mini, x);
	}
	if(mini == INT_MAX)
		cout << -1 << endl;
	else
		cout << mini << endl;
	
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
