//Ryuzaki
#include<bits/stdc++.h>
using namespace std;

void sine() {
  int n, x;
  cin >> n >> x;
  if(n < 3) cout << 1 << endl;
  else {
    int curr = 2, floors = 1;
    while(curr < n) {
      curr += x;
      floors++;
    }
    cout << floors << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--) sine();
  return 0;
}
