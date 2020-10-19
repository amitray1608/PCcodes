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
  string s[n];
  std::map<string, int> c;
  for(int i = 0; i < n; i++){
    cin >> s[i];
    c[s[i]]++;
  }
  cout << "AC x " << c["AC"] << endl;
  cout << "WA x " << c["WA"] << endl;
  cout << "TLE x " << c["TLE"] << endl;
  cout << "RE x " << c["RE"] << endl;
   
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