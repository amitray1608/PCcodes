
#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define deb(x) cout << #x << " = " << x << endl;

template< unsigned MOD >
struct RollingHash {
  vector< unsigned > hashed, power;

  inline unsigned mul(unsigned a, unsigned b) const {
    unsigned long long x = (unsigned long long) a * b;
    unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;
    asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (MOD));
    return m;
  }

  RollingHash(const string &s, unsigned base = 107) {
    int sz = (int)s.size();
    hashed.assign(sz + 1, 0);
    power.assign(sz + 1, 0);
    power[0] = 1;
    for (int i = 0; i < sz; i++) {
      power[i + 1] = mul(power[i], base);
      hashed[i + 1] = mul(hashed[i], base) + s[i];
      if (hashed[i + 1] >= MOD) hashed[i + 1] -= MOD;
    }
  }

  unsigned get(int l, int r) const {
    unsigned ret = hashed[r] + MOD - mul(hashed[l], power[r - l]);
    if (ret >= MOD) ret -= MOD;
    return ret;
  }

  unsigned connect(unsigned h1, int h2, int h2len) const {
    unsigned ret = mul(h1, power[h2len]) + h2;
    if (ret >= MOD) ret -= MOD;
    return ret;
  }

  int LCP(const RollingHash< MOD > &b, int l1, int r1, int l2, int r2) {
    int len = min(r1 - l1, r2 - l2);
    int low = -1, high = len + 1;
    while (high - low > 1) {
      int mid = (low + high) / 2;
      if (get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
      else high = mid;
    }
    return (low);
  }
};

using RH = RollingHash< 1000000007 >;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  string s, t;
  cin >> s >> t;
  
  RH swala(s);
  RH twala(t);
  int n = (int)s.size();
  int m = (int)t.size();
  ll mini = m;
  ll tsum = twala.get(0, m - 1) ;
  deb(tsum);
  for (int i = 0; i <= n - m; i++) {
    cout << i << ' ' << i + m - 1 << '\n';
     ll diff = swala.get(i, i + m - 1);
     deb(diff);
     mini = min(mini, abs(diff - tsum));
  }
  cout << mini << '\n'; 
  return 0;
} //Hajimemashite

