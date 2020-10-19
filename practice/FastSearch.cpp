//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

int n, k;
vector<int> a;

void solve() {
  cin >> n;
  a.resize(n);
  for(int &i : a) cin >> i;
  sort(a.begin(), a.end());
  cin >> k;
  auto Bsearchright = [](int x) {
    int l = 0, h = n-1;
    while(l <= h) {
      int mid = l+(h-l)/2;
      if(a[mid] > x)
        h = mid-1;
      else
        l = mid+1;
    }
    return l;
  };
  auto Bsearchleft = [](int x) {
    int l = 0, h = n-1;
    while(l <= h) {
      int mid = l+(h-l)/2;
      if(a[mid] >= x)
        h = mid-1;
      else
        l = mid+1;
    }
    return l;
  };
  while(k--) {
    int l, r;
    cin >> l >> r;
    l = Bsearchleft(l);
    r = Bsearchright(r);
    // deb(r);
    // deb(l);
    cout << r-l << ' ';
  }
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