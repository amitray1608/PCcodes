#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve(){
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  map<int, vector<int>> mp;
  int k = 1;
  for(int &i : a) cin >> i, mp[i].push_back(k++);
  sort(a.begin(), a.end());
  for(int i = 0; i < n; i++) {
    int p = x - a[i];
    if(p == a[i]) {
      if(mp[p].size() > 1) {
        cout << mp[p][0] << ' ' << mp[p][1];
        return;
      }
    } else if(binary_search(a.begin(), a.end(), p)) {
      cout << mp[a[i]][0] << ' '  << mp[p][0];
      return;
    }
  }
  cout << "IMPOSSIBLE";
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
