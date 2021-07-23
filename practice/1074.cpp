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
  sort(a.begin(), a.end());
  ll maxi = 0;
  for(int i = 0; i < n; i++) {
    maxi += abs(a[i] - a[n/2 - 1]);
  }
  ll cost = 0;
  for (int i = 0; i < n; i++) {
    cost += abs(a[i] - a[n/2]);
  }
  cout << min(cost, maxi);
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
