#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
#define ff first
#define ss second

const int inf = 1e9;

void solve(){
	ll n, w;
  cin >> n >> w;
  ll dp[w+1] = {0};
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    for(ll j = w - x; j >= 0; j--) {
      dp[x+j] = max(dp[x+j], dp[j] + y);
    }
  }
  //for(int i = 0; i <=w; i++)
  //  cout << dp[i] << ' ';
  //cout << endl;
  cout << *max_element(dp, dp+w+1) << endl;
}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
	//	cin >> t;
		while(t--){
			//tt++;
			//cout << "Case #" << t << ": ";
			solve();
		}
	return 0;
}
