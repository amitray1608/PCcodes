#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s, ss;
  cin >> s >> ss;
  int n = s.length(), m = ss.length();
  if(n > m) swap(n, m), swap(s, ss);
  int i = 0;
  string tmp = "", res = "";

  auto check = [&](int d) {
    string p = "";
    int N = n / d, M = m / d;
    int lcm = N * M / __gcd(N, M);
    for(int i = 0; i < lcm; i++) p += tmp;
    return p;
  };
  
  while(i < n) {
    tmp += s[i];
    int sz = tmp.length();
    if(m % sz) {
      i++;
      continue;
    }
    
    bool flag = true;
    for(int k = 0; k < m; k += sz) 
      if(ss.substr(k, sz) == tmp) continue;
      else flag = false;
    
    if(flag) { 
      string p = check(sz);
      if(res.size() == 0) res = p;
      else if(res.size() > p.size()) res = p; 
    }
    i++;
  }
  cout << (res.size() == 0 ? "-1" : res) << '\n';
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

