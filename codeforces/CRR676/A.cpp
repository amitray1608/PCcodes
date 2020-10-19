//Ryuzaki
#include<bits/stdc++.h>
using namespace std;

void sine() {
  int a, b;
  cin >> a >> b;
  int c = a & b;
  int ans = (a ^ c) + (b ^ c);
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
