#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a;
  int count = 0, maxi = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if(!i) a.push_back(x), count = 1;
    else if(x == a.back()){
      count++;
    } else {
      a.push_back(x);
      maxi = max(maxi, count);
      count = 1;
    } 
  }
  maxi = max(count, maxi);
  cout << maxi << '\n';
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


