/*****************************
*  Author :: Πρασαννα Κ. Ροι *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define span(a) begin(a), end(a)

template<typename t>
using vc = vector<t>;

void solve() {
  int n;
  cin >> n;
  vc<int> a(n), pref(n, 0), suf(n, 0);
  for (auto &i: a) cin >> i;
  auto b = a;
  for (int i = 1; i < n; i++) {
    int dif = max(a[i - 1] + 1 - a[i], 0ll);
    a[i] += dif;
    pref[i] = pref[i - 1] + dif;
  }
  for (int i = n - 2; i >= 0; i--) {
    int dif = max(b[i + 1] + 1 - b[i], 0ll);
    b[i] += dif;
    suf[i] = suf[i + 1] + dif;
  }

  int res(LLONG_MAX);
  for (int i = 1; i < n - 1; i++) {
    int dif;
      dif = suf[i + 1] + pref[i];
    res = min(res, dif);
      dif = pref[i - 1] + suf[i];
    res = min(res, dif);
  }
  cout << res << "\n";
}

signed main() {
  // auto start = high_resolution_clock::now();
  __AcHiLlEs

  int t(1);
  cin >> t;
  for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
  // auto stop = high_resolution_clock::now();
  // double duration = duration_cast<microseconds>(stop - start).count();
  // cout << fixed << setprecision(4) << duration / 1000000 << "\n";
  return 0;
}
