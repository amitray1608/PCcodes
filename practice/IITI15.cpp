//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<int> a;

class Fenwik {
  public:
    int n;
    vector<int> bit;
    Fenwik(int _n) : n(_n) {
      bit = vector<int> (n+1, 0);
    }
    void update(int i, int val) {
      while(i <= n) {
        bit[i] += val;
        i +=  i&(-i);
      }
    }
    int get(int i) {
      int sum = 0;
      while(i > 0) {
        sum += bit[i];
        i -= i&(-i);
      }
      return sum;
    }
};

void conversion(int n) {
  vector<int>tmp(n); 
  for(int i = 0; i < n; i++) 
    tmp[i] = a[i];
  sort(tmp.begin(), tmp.end());
  for(int i = 0; i < n; i++) {
    a[i] = (int)(lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin());
  }
}

void solve() {
  int n;
  cin >> n;
  a = vector<int> (n, 0);
  Fenwik f(n);
  for(int &i : a) cin >> i;
  conversion(n);
  int count = 0;
  for(int i = n-1; i >= 0; i--) {
    count += f.get(a[i]-1);
    f.update(a[i], 1);
  }
  int q;
  cin >> q;
  for(int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    // l--, r--;
    cout << f.get(r)-f.get(l) << endl;
    cout << f.get(r)-f.get(l) << endl;
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
