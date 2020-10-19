#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;
vector<int>a;
ll n;

template<typename T>
class BIT {
  int n;
  vector<T> bit;
public:
  BIT(int N) {
    bit.assign(N + 1 , 0);
    n = N;
  }
  void update(int idx , T val) {
    idx++;
    while(idx <= n) {
      bit[idx] += val;
      idx += (idx & -idx);
    }
  }
  int sum(int idx) {
    idx++;
    T res = 0;
    while(idx > 0) {
      res += bit[idx];
      idx -= (idx & -idx);
    }
    return res;
  }

};
void convert() {
  vector<int>tmp = a;
  sort(tmp.begin(), tmp.end());
  for(int i = 0; i < n; i++) {
    a[i] = lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin() + 1;
  }
}

void solve(){
  cin >> n;
  a.resize(n);
  for(int &i : a) cin >> i;
  convert();
  /*
  bool flag = false;
  for(int i = 1; i < n; i++) {
    if(a[i-1] <= a[i])
       flag = true;
  }
  */
  BIT <int> b(n+1);
  ll count = 0, total = ((n * (n-1)) >> 1) - 1;
  for(int i = n-1; i >= 0; i--)
    count += b.sum(a[i]-1), b.update(a[i], 1);

  cout << (count <= total ? "YES" : "NO") << endl;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
  //cout << "Case #" << ++t << ": ";
    solve();
  }
  return 0;
}
