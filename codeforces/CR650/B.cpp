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
  int a[n];
  int odd = 0, even = 0;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    if((i&1 and ~a[i]&1))
        even++;
    if(~i&1 and a[i]&1)
        odd++;
  }
  if(even != odd)
      cout << -1 << endl;
  else
      cout << even << endl;
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