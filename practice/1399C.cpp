//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

int n;
vector<int> a;
int maxi = 0;
map<int, int>c, d;

int check(int x) {
  int count = 0;

  for(auto i : d) {
    if(x-i.first < 0) continue;
    if(d[x-i.first] > 0 and d[i.first] > 0) {
      if(x-i.first == i.first) {
        count += i.second/2;
        i.second /= 2;
      } else {
        count += min(i.second, d[x-i.first]);
        i.second = 0;
        d[x-i.first] = 0;      
      }
    }
  }
  return count;
}

void solve() {
  cin >> n;
  a.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
    c[a[i]]++;
  }
  maxi = 0;
  for(int i = 1; i < 101; i++) {
    d = c;
    int count = check(i);
    maxi = max(maxi, count);
    d.clear();
  }
  cout << maxi << endl;
  a.clear();
  c.clear();
  d.clear();
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