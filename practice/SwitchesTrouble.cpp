#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

void solve(){
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  int seg = 0;
  for(int i = 1; i  < n; ++i) 
    if(s[i] == '0' and s[i-1] == '1') seg++;
  if(s[0] == '0') seg++;
  cout << (seg ? ((seg-1)*min(a, b) + b) : 0) << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
  //cout << "Case #" << ++t << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
