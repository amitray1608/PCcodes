#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve(){
  int n, x;
  cin >> n >> x;
  vector<int> w(n);
  for(int &i : w) cin >> i;
  sort(w.begin(), w.end());
  int count = 0;
  vector<bool> vis(n, false);
  for(int i = 0; i  < n; i++) {

  }
  cout << count ;
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
