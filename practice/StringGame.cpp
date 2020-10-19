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
  string t, p;
  cin >> t >> p;
  int n = (int)t.size();
  vector<int> a(n);
  for(int &i : a) cin >> i;
  auto check = [&](int x) {
    string c = "", cp = t;
    for(int i = 0; i < x; i++)
      cp[a[i]-1] = '*';
    int i = 0, j = 0;
    while(i < n) {
      if(cp[i] == '*') i++;
      else if(cp[i] == p[j]) c.push_back(cp[i]), i++, j++;
      else
        i++;
    }
    // deb(c);
    return (c == p);
  };

  int l = 0, h = n;
  while(l <= h) {
    int mid = l + (h-l)/2;
    // deb(mid);
    if(check(mid)) 
      l = mid + 1;
    else
      h = mid - 1;
  }
  cout << h << endl;
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