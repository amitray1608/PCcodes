
#include <bits/stdc++.h>

using namespace std;

void solve() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  int hr = stoi(s.substr(0, 2));
  int mi = stoi(s.substr(3, 2));
  while (n--) {
    mi++;
    if (mi == 60) 
      hr++, mi = 0;
    hr %= 24;
  }
  string hour = to_string(hr);
  string minut = to_string(mi);
  while (hour.size() < 2) 
    hour = "0" + hour;
  while (minut.size() < 2)
    minut = "0" + minut;
  cout << hour << ':' << minut << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  //cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite


