//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve() {
  int n;
  string ntl, act;
  cin >> n >> ntl;
  int sum = 0;
  for(int j = 0; j < n; j++){
    cin >> act;
    if(act == "CONTEST_WON") {
      int rank;
      cin >> rank;
      sum += 300 + ((rank < 20) ? (20 - rank) : 0);
    } else if(act == "TOP_CONTRIBUTOR"){
      sum += 300;
    } else if(act == "BUG_FOUND"){
      int severity;
      cin >> severity;
      sum += severity;
    } else
      sum += 50;
  }
  cout << sum/((ntl == "INDIAN") ? 200 : 400) << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(10);
  int t = 1;
  cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  