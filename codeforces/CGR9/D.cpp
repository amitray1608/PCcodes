//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
  int n;
  cin >> n;
  int a[n], f[n+1];
  memset(f, 0, sizeof f);
  for(int &i : a) cin >> i, f[i]++;
  bool flag = true;
  for(int i = 1; i < n; i++){
    if(a[i-1] > a[i])
      flag = false;
  }
  if(flag){
    cout << 0 << endl;
    return;
  }
  int x = n;
  for(int i = 1; i <= 2*n; i++){
    if(i == n or i == 2*n){
      cout << 1 << ' ';
      x = n;
    }
    else
      cout << x-- << ' ';
  }
  cout << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  