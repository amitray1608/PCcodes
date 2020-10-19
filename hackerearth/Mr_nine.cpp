//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
#define deb(x) cout << #x << " = " << x << endl;
vector <int> G[300005];
bool vis[300005] = {false};

int count = 0;
int  u, v;

int dfs(int s){	
	if(s == v) return 0;

	vis[s] = true;
	 cnt += 2;
	//cout << s << endl;
	for(int i : G[s]){
		if(!vis[i])
			cnt += dfs(i);
	}
	return cnt;
}


void solve()
{
	int n;
	cin >> n >> u >> v;
	for(int i = 1; i<n; i++){
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vis[u] = true;
	vis[v] = true;
	 dfs(u);
	cout << ans << endl;
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		//cin >> t;
		while(t--){
			solve();
		}
	return 0;
}
	
