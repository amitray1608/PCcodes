//author: hitch_hiker42;
#include<bits/stdc++.h>
using namespace std;

//solution:
mt19937_64 mersenne{static_cast<mt19937_64::result_type>(time(nullptr))};

int rng(int l, int r) {
  return uniform_int_distribution<int>(l, r)(mersenne);
}

string rsg(int n) {
  string s = "";
  for(int i = 0; i < n; ++i) s += 'a' + (int)rng(0, 25);
  return s;
}

void hike() {
  int t = rng(1, 50);
  while(t--) {
    cout << rng(1, 100) << "\n";
    cout << rsg(rng(1, 1000)) << "\n";
    cout << rsg(rng(1, 1000)) << "\n";
  }
  cout << 0;
}

signed main() {
  freopen("output.txt", "w", stdout);
  int t = 1; //cin >> t;
  while(t--) hike();
  return 0;
} //farewell, until we meet again..
