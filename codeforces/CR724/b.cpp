
#include<bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (int i = 0; i < 4; i++) {
    int N = 1;
    for (int j = 0; j < i; j++) {
      N *= 26;
    }
    for (int mask = 0; mask < N; mask++) {
      string curr;
      int val = mask, k = 0;
      while (k < i) {
        int left = val % 26;
        curr.push_back('a' + left);
        val /= 26;
        k++;
      }
      reverse(curr.begin(), curr.end());
      if (s.find(curr) == -1) {
        cout << curr << '\n';
        return;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); 
  int t = 1;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    solve();   
  }	
  return 0;
} //Hajimemashite

