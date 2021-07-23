
#include<bits/stdc++.h>

using namespace std;
#define deb(x) cout << #x << " = " << x << endl;


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); 
  cout.tie(nullptr);
  string s;
  cin >> s;
  int n = (int)s.size();
  bool ok = true;
  if (n <= 2) {
    cout << "YES" << '\n';
    return 0;
  }
  int fir = s[0] - 'A';
  int sec = s[1] - 'A';
  for (int i = 2; i < n; i++) {
    if ((fir + sec) % 26 != s[i] - 'A') {
      ok = false;
    }
    int tmp = (fir + sec) % 26;
    fir = sec;
    sec = tmp;
  }
  cout << (ok ? "YES" : "NO") << '\n';
  return 0;
} //HajimemashiteANNA


