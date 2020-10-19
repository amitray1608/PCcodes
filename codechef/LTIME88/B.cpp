//Ryuzaki
#include<bits/stdc++.h>
using namespace std;

void sine() {
  int n;
  cin >> n;
  vector<int>a(n+1);
  bool flag = true;
  for(int i = 1; i < n+1; i++) cin >> a[i];
  for(int i = 1; i < n+1; i++) {
    if((a[i] == i or i%a[i] == 0)) continue; 
      flag = false;
  }
  cout << (flag ? "YES" : "NO") << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--) sine();
  return 0;
}
