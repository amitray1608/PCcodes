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
	int n, k, q;
	cin >> n >> k >> q;
	int a[n];
	for(int &i : a) cin >> i;
	vector<pair<int, int>>v;
	for(int i = 0; i<n; i++){
		v.push_back({a[i], i+1});
	}
	sort(v.begin(), v.end());
	int dp[n+1];
	dp[0] = 0;
	for(int i = 1; i<n; i++){
            if (v[i].first - v[i - 1].first <= k) {
                dp[v[i].second] = dp[v[i - 1].second];
            }
            else {
                dp[v[i].second] = 1 + dp[v[i - 1].second];
            }
	}
	//for(int i = 0; i <= n; i++)
		//cout << dp[i] << " ";
	//cout << endl;
	while(q--){
		int x, y;
		cin >> x >> y;
		if(!abs(dp[x] - dp[y]))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
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
