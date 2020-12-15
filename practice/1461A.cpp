#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve() {
  int n, k;
  cin >> n >> k;
  string a = "abc";
  int i = 0;
//  deb(a);
//  return;
  string ans = "";
  while(i < n) {
    ans += a;
    i += 3;
  }
  for(int i = 0; i < n; i++)
    cout << ans[i];
  cout << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
