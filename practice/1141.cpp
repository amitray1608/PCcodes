#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int &i : a) cin >> i;
  map<int, int> pos;
  int maxi = 0, curr = 0;
  for(int i = 0; i < n; i++) {
    if(pos.find(a[i]) != pos.end())
      curr = max(pos[a[i]] + 1, curr);
    maxi = max(maxi, i - curr + 1);
    pos[a[i]] = i;
  }
  cout << maxi;
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
