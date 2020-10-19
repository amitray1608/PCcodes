//Ryuzaki
#include<bits/stdc++.h>
using namespace std;

void sine() {
  int n;
  cin >> n;
  for(int i = 0; i*7 <= n; i++) {
    int x = i*7;
    int p = n - x;
    bool flag = false;
    for(int j = 0; j*5 <= n; j++) {
      int xx = j*5;
      p = p - xx;
      if(p >= 0 and p%3 == 0) {
        flag = true;
        cout << p/3 << ' ' << j << ' ' << i << endl;
        break;
      }
    }
    if(flag) return;
  }
  cout << -1 << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--) sine();
  return 0;
}
