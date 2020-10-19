#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

void solve(){
  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> a;
  for(int i = 0; i < n; i++) {
    int xx;
    cin >> xx;
    a.push_back({xx/x + (xx%x ? 1 : 0), i});
  }
  sort(a.begin(), a.end());
  for(int i = 0; i < n; i++)
    cout << a[i].second + 1 << ' ';
  cout << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}
