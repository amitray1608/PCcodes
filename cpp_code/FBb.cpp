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
  string s;
  cin >> s;
  int A = 0, B = 0;
  for(char c : s) {
    (c == 'A') ? A++ : B++;
  }
  cout << (abs(A-B) == 1 ? 'Y' : 'N') << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    tt++;
    cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  