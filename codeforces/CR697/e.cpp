
#include <bits/stdc++.h>

using namespace std;

template <int T_MOD>
struct Modll {
  static constexpr int MOD = T_MOD;
private:
  using ll = long long;
  int v;

  static int minv(int a, int m) {
    a %= m;
    if (a < 0) a += m;
    int b = m, u = 0, v = 1;
    while (a) {
      int t = b / a;
      b -= t * a; swap(a, b);
      u -= t * v; swap(u, v);
    }
    assert(b == 1);
    if (u < 0) u += m;
    return u;
  }

public:

  Modll() : v(0) {}
  template<class T> Modll(T v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
  explicit operator int() const { return v; }
  friend std::ostream& operator << (std::ostream& out, const Modll& n) { return out << int(n); }
  friend std::istream& operator >> (std::istream& in, Modll& n) { ll v_; in >> v_; n = Modll(v_); return in; }
  friend bool operator == (const Modll& a, const Modll& b) { return a.v == b.v; }
  friend bool operator != (const Modll& a, const Modll& b) { return a.v != b.v; }

  Modll inv() const {
    Modll res;
    res.v = minv(v, MOD);
    return res;
  }

  Modll neg() const {
    Modll res;
    res.v = v ? MOD - v : 0;
    return res;
  }

  Modll operator- () const {
    return neg();
  }

  Modll operator+ () const {
    return Modll(*this);
  }

  Modll& operator ++ () {
    v++;
    if (v == MOD) v = 0;
    return *this;
  }

  Modll& operator -- () {
    if (v == 0) v = MOD;
    v --;
    return *this;
  }

  Modll& operator += (const Modll& o) {
    v += o.v;
    if (v >= MOD) v -= MOD;
    return *this;
  }

  Modll& operator -= (const Modll& o) {
    v -= o.v;
    if (v < 0) v += MOD;
    return *this;
  }

  Modll& operator *= (const Modll& o) {
    v = int(ll(v) * ll(o.v) % MOD);
    return *this;
  }

  Modll& operator /= (const Modll& o) {
    return *this *= o.inv();
  }

  friend Modll operator ++ (Modll& a, int) { Modll r = a; ++a; return r; }
  friend Modll operator -- (Modll& a, int) { Modll r = a; --a; return r; }
  friend Modll operator + (const Modll& a, const Modll& b) { return Modll(a) += b; }
  friend Modll operator - (const Modll& a, const Modll& b) { return Modll(a) -= b; }
  friend Modll operator * (const Modll& a, const Modll& b) { return Modll(a) *= b; }
  friend Modll operator / (const Modll& a, const Modll& b) { return Modll(a) /= b; }  
};

const int mod = 1000000007;
using Mint = Modll<mod>;

vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);

Mint C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fact.size() < n + 1) {
    fact.push_back(fact.back() * (int) fact.size());
    inv_fact.push_back(1 / fact.back());
  }
  return fact[n] * inv_fact[k] * inv_fact[n - k];
}

Mint power(Mint x, int p) {
  Mint ans = Mint(1);
  while(p) {
    if(p & 1) {
      ans *= x;
    }
    x *= x;
    p >>= 1;
  }
  return ans;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int &i : a) cin >> i;
  sort(a.rbegin(), a.rend());
  int count = 0, less = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] == a[k - 1]) {
      count += 1;
      less += (i < k);
    }
  }
  cout << C(count, less) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite

