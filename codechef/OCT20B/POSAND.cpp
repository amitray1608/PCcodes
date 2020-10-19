//Ryuzaki
#include<bits/stdc++.h>
using namespace std;

bool check(int x) {
  return (x > 0 && (0 == (x&(x-1))));
}

void sine() {
  int n;
  cin >> n;
  if(check(n)) {
    cout << -1 << endl;
    return;
  }
  int rem = (int)(floor(log(n) / log(2)));
  int last = (int)pow(2, rem);
  if(n%2) {
    for(int i = last; i < n+1; ++i)
      cout << i << ' ';
  }
  cout << 1 << ' ';
  for(int i = 2; i < rem + 1; ++i) {
    int e = (int)pow(2, i) - 1, b = (int)pow(2, i - 1);
    int m = (e + b)/2;
    cout << m + 1 << ' ';
    for(int k = b + 1; k < e+1; ++k)
      cout << (k == m + 1 ? b : k) << ' ';
  }
  
  if(n%2 == 0)
    for(int i = n; i >= pow(2, rem); --i)
      cout << i << ' ';
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--) sine();
  return 0;
}
