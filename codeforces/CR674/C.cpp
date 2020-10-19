//Ryuzaki
#include<bits/stdc++.h>
using namespace std;
//#define int int64_t

void sine() {
  int n;
  cin >> n;
  if(n == 1) {
    cout << 0 << endl;
  } else {
    double a = ceil(sqrt(n));
    double b = ceil(n/a);
    cout << a + b - 2 << endl; 
  }
}

signed main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--) sine();
  return 0;
}
