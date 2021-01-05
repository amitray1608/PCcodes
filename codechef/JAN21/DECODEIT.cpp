#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    string s, ans = "";
    cin >> s;
    for(int i = 0; i < n; i += 4) {
      string tt = string(s.begin() + i, s.begin() + i + 4);
      int l = 0, r = 15, j = 0;
      while(l < r and j < 4) {
        int mid = (l + r) / 2;
        if(tt[j] == '0') {
          r = mid;      
        } else {
          l = mid;
        }
        j++;
      }
      ans += char(r + 'a');
    }
    cout << ans << '\n';
  }
  return 0;
}
