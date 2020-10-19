#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
const int inf = 1e9;
vector<ll>h, ans;

ll recc(int n) {
  if(ans[n] != -1)
    return ans[n];
  if(n == 0)
    return 0;
  if(n < 0)
    return inf;
  return ans[n] = min(recc(n-1) + abs(h[n] - h[n-1]), recc(n-2) + abs(h[n] - h[n-2]));

}

void solve(){
  int n;
  cin >> n;
  h.resize(n, 0);
  ans.resize(n, -1);
  for(int i = 0; i < n; i++) cin >> h[i];
  ans[0] = 0;
  ll anss = recc(n-1);

  /*
  ans[0] = 0;
  ans[1] = abs(h[0]-h[1]);
  for(int i = 2; i < n; i++) {
    ans[i] = min(ans[i],  ans[i-1] + abs(h[i]-h[i-1]));
    ans[i] = min(ans[i],  ans[i-2] + abs(h[i]-h[i-2]));
  }
  for(int &i : ans) cout << i << ' ';
  cout << endl;
  */
  cout << anss << endl;
}

int main(){
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
		//cin >> t;
		while(t--){
			//tt++;
			//cout << "Case #" << t << ": ";
			solve();
		}
	return 0;
}
