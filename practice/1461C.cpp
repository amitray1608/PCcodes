#include<bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  unordered_map<int, int> mp;
  for(int &i : a) cin >> i;
  
  sort(a.begin(), a.end());
  vector<int> pre(n, 0);
  for(int i = 0; i < n; i++) {
    if(!i) pre[i] = a[i];
    else pre[i] = pre[i - 1] + a[i];
  }
  
  function<void(int, int)> subsetsum = [&](int i, int j) {
    if(i > j) return;
    int diff = pre[j] - (i ? pre[i - 1] : 0);
    mp[diff]++ ;
    if(i == j or a[i] == a[j]) return;
    int mid = (a[i] + a[j]) / 2;
    int up = upper_bound(a.begin(), a.end(), mid) - a.begin() - 1;
    subsetsum(i, up); subsetsum(up + 1, j);
  };
  subsetsum(0, n - 1);
  while(q--) {
    int s;
    cin >> s;
    cout << (mp[s] ? "Yes" : "No") << endl;
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
