//Ryuzaki
#include<bits/stdc++.h>
using namespace std;

void sine() {
  int n;
  cin >> n;
  int in[n] = {0};
  for(int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    in[v]++;
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans += max(0, in[i]-1);
  }
  cout << ans << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--) sine();
  return 0;
}
