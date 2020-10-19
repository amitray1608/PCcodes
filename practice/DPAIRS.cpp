//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  int posina = 0, posinb = 0;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    if(a[i] > a[posina])
      posina = i;
  }
  for(int i = 0; i < m; i++) {
    cin >> b[i];
    if(b[i] < b[posinb])
      posinb = i;
  }
  for(int i = 0; i < n; i++)
    cout << i << ' ' << posinb << endl;
  for(int i = 0; i < m; i++)
    if(i !=  posinb)
    cout << posina << ' ' << i << endl;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  // cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  