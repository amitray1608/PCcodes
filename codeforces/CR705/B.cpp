
#include <bits/stdc++.h>

using namespace std;
#define deb(x) cout << #x << " = " << x << endl;


bool check(int H, int M, int h, int m) {
  string resh = to_string(H);
  string resm = to_string(M);
  map<char, char> same = { 
  {'1', '1'}, {'0', '0'},
  {'2', '5'}, {'5', '2'},
  {'8', '8'},
  };

  while (resh.size() < 2) 
    resh = '0' + resh;
  while (resm.size() < 2)
    resm = '0' + resm;
  
  for (char &x : resh) 
    if (!same.count(x)) { 
      return false;
    }
  for (char &x: resm) 
    if (!same.count(x)) {
      return false;
    }
  
  reverse(resh.begin(), resh.end());
  reverse(resm.begin(), resm.end());
  
  for (char &x : resh)
    x = same[x];
  for (char &x : resm)
    x = same[x];
  int hr = stoi(resh);
  int mt = stoi(resm);
  
  if (hr >= 0 and hr < m and mt >= 0 and mt < h) 
    return true;

  return false;
}

void solve() {
  int h, m;
  cin >> h >> m;
  string s;
  cin >> s;
  int modh, modm;
  modh = (int)(s[0] - '0') * 10 + (s[1] - '0');
  modm = (int)(s[3] - '0') * 10 + (s[4] - '0');
  int times = 100;
  while (true) {
    bool ok = check(modh, modm, h, m);
    if (ok) {
      if (modh >= 0 and modh <= 9)
        cout << 0;
      cout << modh  << ':';
      if (modm >= 0 and modm <= 9)
        cout << 0;
      cout << modm << '\n';
      return;
    }
    modm++;
    if (modm == m) {
      modm %= m;
      modh++;
    }
    modh %= h;
  }
  cout << "00:00" << '\n';
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


