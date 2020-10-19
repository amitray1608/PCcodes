//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<vector<int>>adj;
vector<int>in, out;

void solve(){
	int n;
  cin >> n;
  adj.resize(n);

  for(int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0);
  /*
  int q;
  cin >> q;
  while(q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    //continue;
    cout << l.query(u, v) << endl;
  }
  */
}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
//		cin >> t;
		while(t--){
			//tt++;
			//cout << "Case #" << t << ": ";
			solve();
		}
	return 0;
}
/*
8
1 2
2 5
2 6
1 3
1 4
4 7
4 8
6
1 7
7 8 
5 6
5 7
2 4
5 3
*/
