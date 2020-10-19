//Ryuzaki
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void sine() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll ans = abs(a - c) + abs(b - d);
  if(!abs(a - c)) cout << abs(b - d) << endl;
  else if(!abs(b - d)) cout << abs(a - c) << endl;
  else cout << ans + 2 << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--) sine();
  return 0;
}
