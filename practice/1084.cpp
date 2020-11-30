#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve(){
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n), b(m), vis(m, 0);
  for(int &i : a) cin >> i;
  for(int &i : b) cin >> i;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int ans = 0, house = 0;
  for(int i = 0; i < n; i++) {
    while(house < m) { 
      if(abs(b[house] - a[i]) <= k and !vis[house]) {
        ans++;
        vis[house] = 1;
        house++;
        break;
      } else if(b[house] - a[i] > k) break;
//      cout << "OK" << endl;
      house++;
    }
  }
  cout << ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
//    cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
