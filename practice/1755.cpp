#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve(){
  string s;
  cin >> s;
  string ans = "";
  vector<int> f(26, 0);
  for(char c : s) 
    f[c - 'A']++;
  int count = 0;
  char odd;
  for(int i = 0; i < 26; i++) 
    if(f[i]&1) odd = 'A' + i, count++;
  if(count > 1) {
    cout << "NO SOLUTION";
    return;
  } 
  for(int i = 0; i < 26; i++) {
    ans += string(f[i]/2, ('A'+i));
  }
//  deb(ans);
  string x = ans;
  if(count&1) ans += odd;
  reverse(x.begin(), x.end());
  ans += x;
  cout << ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
