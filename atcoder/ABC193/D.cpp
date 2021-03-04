
#include <bits/stdc++.h>

using namespace std;

void solve() {
  cout << fixed << setprecision(15);
  int k;
  cin >> k;
  string t, a;
  cin >> t >> a;
  vector<int> ft(10, 0), fa(10, 0);
  for (char c : t) {
    int ind = c - '0';
    ft[ind]++;
  }
  for (char c : a) {
    int ind = c - '0';
    fa[ind]++;
  }   
  long long sumt = 0, suma = 0;
  long long countt = 0, counta = 0;
  for (int i = 1; i < 10; i++) {
    sumt += i * pow(10LL, ft[i]);
  }
  for (int i = 1; i < 10; i++) {
    suma += i * pow(10LL, fa[i]);
  }

  for (int i = 1; i < 10; i++) {
    
  } 

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


