//Ryuzaki
#include<bits/stdc++.h>
using namespace std;

void sine() {
  int n;
  cin >> n;
  int sum = 0;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sum += x;
  }
  cout << (sum >= 0 ? "YES" : "NO") << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--) sine();
  return 0;
}
