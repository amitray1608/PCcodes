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
  for(int &i : a) cin >> i;
  sort(a, a+n);
  for(int i : a) cout << i << ' ';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  #ifndef RAY
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
  int t = 1;
  // cin >> t;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  