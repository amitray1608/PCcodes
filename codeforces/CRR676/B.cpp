//Ryuzaki
#include<bits/stdc++.h>
using namespace std;

void sine() {
  int n;
  cin >> n;
  vector<string> a(n);
  for(auto &i : a) cin >> i;
  int x[4] = {0};
  if(a[0][1] == '1') x[0] = 1;
  if(a[1][0] == '1') x[1] = 1;
  if(a[n - 1][n - 2] == '1') x[2] = 1;
  if(a[n - 2][n - 1] == '0') x[3] = 1;
  if(x[0]) {
    if(
  } else {

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
