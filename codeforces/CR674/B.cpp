//Ryuzaki
#include<bits/stdc++.h>
using namespace std;

void sine() {
  int n, m;
  cin >> n >> m;
  bool flag = false, flag2 = false;
  int count = 0;
  for(int i = 0; i < n; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(b == c) flag = true;
    if(a == d and b == c) flag2 = true;
  }
  if(m == 2 and flag2) cout << "YES" << endl;
  else if(flag and ~m&1 and m > 2) cout << "YES" << endl;
  else
    cout << "NO" << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--) sine();
  return 0;
}
