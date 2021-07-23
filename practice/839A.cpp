
#include<bits/stdc++.h>

using namespace std;
#define deb(x) cout << #x << " = " << x << endl;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  
  int n, k;
  cin >> n >> k;
  bool ok = false;
  int current = 0, day = 1, left = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    left += x;
    current += min(8, left);
    left -= min(8, left);
    if (!ok and current >= k) {
      ok = true;
      day = i + 1;
    }
//    deb(current);
  }
  cout << (!ok ? -1 : day) << '\n';
  
  return 0;
} //Hajimemashite
