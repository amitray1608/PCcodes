#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int n;
    cin >> n;
    int curr = 10 - n % 10, i = 0;
    vector<int> a;
    while(i < n) {
      i++;
      a.push_back(curr);
      curr = ( curr + 1 ) % 10;
    }
    reverse(a.begin(), a.end());
    for (i = 0; i < n; i++) {
      cout << a[i];
    } 
    cout << '\n';
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
