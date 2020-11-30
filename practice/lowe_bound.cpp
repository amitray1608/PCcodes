#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve(){
  vector<int> a = {1, 2, 3, 4, 5, 5, 5, 7};
  cout << lower_bound(a.begin(), a.end(), 1) - a.begin() << endl;
  cout << lower_bound(a.begin(), a.end(), 6) - a.begin() << endl;
  cout << lower_bound(a.begin(), a.end(), 8) - a.begin() << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
//    cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
