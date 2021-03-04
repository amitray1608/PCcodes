
#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int v, t, s, d;
  cin >> v >> t >> s >> d;
  int y =  s * v;
  int x = v * t;
  if (d >= x and d <= y) cout << "No\n";
  else  cout << "Yes\n";
  return 0;
} //Hajimemashite
