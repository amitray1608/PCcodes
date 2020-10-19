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
  int n, v, w;
  cin >> n >> v >> w;
  vector<pair<int, int>>p(n);
  for(int i = 0; i < n; i++)
    cin >> p[i].first >> p[i].second;
  vector<int> in(v), out(w);
  for(int &i : in) cin >> i;
  for(int &i : out) cin >> i;
  auto compare = [](pair<int, int> a, pair<int , int> b) {
    return (a.second - a.first <= b.second - b.first);
  };
  sort(p.begin(), p.end(), compare);
  sort(in.begin(), in.end());
  sort(out.begin(), out.end());
  // for(auto i : p)
  //   cout << i.first << ' ' << i.second << endl;
  int mini = INT_MAX;
  for(int i = 0; i < n; i++) {
    if(p[i].second - p[i].first > mini) break;
    int x = lower_bound(in.begin(), in.end(), p[i].first) - in.begin();
    // deb(x);
    if(p[i].first != in[x])
      x--;
    x = in[x];
    int y = *lower_bound(out.begin(), out.end(), p[i].second);
    // deb(y);
    if(y < p[i].second)
      y = INT_MAX;
    mini = min(mini, y-x+1);
  }
  cout << mini << endl;
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