#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve() {
  string s;
  cin >> s;
  int n = s.size();
  if(n == 1) {
    cout << 0 << '\n'; 
    return;
  }
    int count = 0;
  for(int i = 0; i < n - 2; i++) {
    if(s[i] == s[i + 1]) count++;
    if(s[i] == s[i + 2]) count++;
  }
  if(s[n - 1] == s[n - 2]) count++;
//  if(s[n - 1] == s[n - 2]) count++;
  cout << count << '\n';
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
