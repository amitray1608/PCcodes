//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int sizz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve() {
  int n;
  cin >> n;
  map<int, int> fre, ans;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    fre[x]++;
  }
  for(auto &i : fre) {
    ans[i.second]++;
  }
  int val = 0, siz = 0;
  for(auto i : ans) {
    if(i.second > siz) {
      val = i.first;
      siz = i.second;
    }
    if(i.second == siz) 
      val = min(val, i.first);
  }
  cout << val << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  