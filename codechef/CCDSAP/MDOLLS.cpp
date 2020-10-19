//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

bool compare(const pair<int, int>&a, const pair<int, int>&b){
		return(a.second < b.second);
}

void solve(){
	int n;
	cin >> n;
	vector<pair<int, int>>v(n), c(n)	;
	for(int i = 0; i < n; i++){
		cin >> v[i].first >> v[i].second;
		c[i].first = v[i].first, c[i].second = v[i].second;
	}
	sort(v.begin(), v.end());
	sort(c.begin(), c.end(), compare);
	int ans = 0;
	int dp[n];
	for(int i = 0; i < n; i++) dp[i] = 1;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++)
		if(v[j].first < v[i].first && v[j].second < v[i].second)
			dp[i] = max(dp[i], dp[j]+1);
	}
	//sort(dp, dp+n);
	set<int>ss;
	for(int i = 0; i < n; i++){
		//cout << dp[i] << " ";
		ss.insert(dp[i]);
	}
	ans = (n-ss.size())+1;
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
