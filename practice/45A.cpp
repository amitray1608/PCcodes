
#include <bits/stdc++.h>

using namespace std;

map<int, string> numToMonth = {
  {1, "January"}, {2, "February"}, {3, "March"},
  {4, "April"}, {5, "May"}, {6, "June"},
  {7, "July"}, {8, "August"}, {9, "September"},
  {10, "October"}, {11, "November"}, {12, "December"}
};
map<string, int> monthToNum = {
  {"January", 1}, {"February", 2}, {"March", 3},
  {"April", 4}, {"May", 5}, {"June", 6},
  {"July", 7}, {"August", 8}, {"September", 9},
  {"October", 10}, {"November", 11}, {"December", 12}
};

void solve() {
  string s; cin >> s;
  int k; cin >> k;
  int curr = monthToNum[s];
  curr += k;
  curr %= 12;
  if (curr == 0) curr = 12;
  cout << numToMonth[curr] << '\n';
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


