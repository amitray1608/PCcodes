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
  int n;
  cin >> n;
  string s;
  cin >> s;
  int count = 0;
  vector<int> pos, oe[2];
  for(int i = 0; i < n; i++) {
    int a = s[i]&1;
    int x = (int)oe[a^1].size();
    if(x) {
      pos.push_back(oe[a^1].back());
      oe[a^1].pop_back();
      oe[a].push_back(pos.back());
    } else {
      count++;
      oe[a].push_back(count);
      pos.push_back(count);
    }
  }
  cout << count << endl;
  for(int &i : pos)
    cout << i << ' ';
  cout << endl;
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