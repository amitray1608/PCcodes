
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  
  int n;
  cin >> n;
  if (~n & 1) {
    cout << "Draw" << '\n';
    return 0;
  }
  bool ok = (n % 5);
  cout << (ok ? "Win" : "Lose") << '\n'; 
  return 0;
} //Hajimemashite

