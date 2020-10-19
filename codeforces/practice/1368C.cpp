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
  cout << 4+(3*n) << endl;
  cout << "0 0 \n0 1\n1 0\n1 1\n";
  for(int i = 0; i < n; i++) {
    cout << i+1 << " " << i+2 << endl;
    cout << i+2 << " " << i+2 << endl;
    cout << i+2 << " " << i+1 << endl;
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  