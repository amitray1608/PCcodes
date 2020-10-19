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
  string a, b;
  map<string, int>check;
  int ans = n;
  for(int i= 0; i < n; i++) {
    cin >> a >> b;
    check[b]++;
  }
  for(auto i : check){
    for(auto j : check) {
      if(i.first == j.first) continue;
      ans += i.second*j.second; 
    }
  }
  cout << ans << endl;
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