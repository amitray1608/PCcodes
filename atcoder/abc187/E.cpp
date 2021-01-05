#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int maxn = 2e5 + 1;

int vis[maxn];
ll val[maxn];

//Brute Force.

void dfs(vector<int> adj[], int s, int x, int k) {
	if(s != x && !vis[s]) {
		vis[s] = 1;
		val[s] += k;
		for(auto i : adj[s]) {
			dfs(adj, i, x, k);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> adj[n];
	vector<pair<int, int>> arr;
	for(int i = 0; i < n - 1; i++) {
		int a, b;
    cin >> a >> b;
    a--, b--;
		arr.push_back({a, b});
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
  int q;
	cin >> q;
	while(q--) {
    int t, e, x;
		for(int i = 0; i < n; i++) {
			vis[i] = 0;
		}
		cin >> t >> e >> x;
		if(t == 1) dfs(adj, arr[e-1].first, arr[e-1].second, x);
		else dfs(adj, arr[e-1].second, arr[e-1].first, x);
	}
	for(int i = 0; i < n; i++) {
		cout << val[i] << endl;
	}
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
