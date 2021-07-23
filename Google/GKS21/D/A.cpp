
#include<bits/stdc++.h>

using namespace std;
#define int int64_t
int a[4][4];

bool check(int x, int b, int c) {
  return (2 * b == (x + c));
}

void solve() {
  memset(a, 0, sizeof a);
  cin >> a[0][0] >> a[0][1] >> a[0][2];
  cin >> a[1][0] >> a[1][2];
  cin >> a[2][0] >> a[2][1] >> a[2][2];
  int count = check(a[0][0], a[0][1], a[0][2]);
  count += check(a[2][0], a[2][1], a[2][2]);
  count += check(a[0][0], a[1][0], a[2][0]);
  count += check(a[0][2], a[1][2], a[2][2]);
  map<int, int> mp;
  if (~ (a[0][0] + a[2][2]) & 1) {
    mp[(a[0][0] + a[2][2]) / 2]++;
  }
  if (~ (a[0][1] + a[2][1]) & 1) {
    mp[(a[0][1] + a[2][1]) / 2]++;
  }

  if (~ (a[0][2] + a[2][0]) & 1) {
    mp[(a[0][2] + a[2][0]) / 2]++;
  }
  if (~ (a[1][0] + a[1][2]) & 1) {
    mp[(a[1][0] + a[1][2]) / 2]++;
  }
  int mid = 0;
  for (auto i : mp) {
    mid = max(mid, i.second);
  }
  cout << count + mid << '\n';
}

int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    cout << "Case #" << tt << ": ";
    solve();
  }	
  return 0;
} //Hajimemashite

