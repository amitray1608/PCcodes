#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

void solve(){
  int n;
  cin >> n;
  int count = 0, ans = 0;
  for(int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if( x== y )
      count++;
    else 
      count = 0;
    if(count == 3)
      ans = 1;
  }
  cout << (ans ? "Yes" : "No") << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
