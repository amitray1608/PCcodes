#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int maxn = 10;

void solve() {
  int n;
  cin >> n;
  ll range[maxn] = {0};
  for(int i = 0; i < n; i++) {
    int l, r, z;
    cin >> l >> r >> z;
    r--;
//    range[l] += z;
    range[r] += z;
  }
  for(int i = 0; i < maxn; i++) {
    cout << range[i] << ' ';
  } cout << '\n';
  auto check = [&](int x) {
    ll curr = 0;
    for(int i = 0; i < maxn; i++) {
      curr += x;
      if(curr < range[i]) return false;
    }
    return true;
  };
  int l = 1, r = 200001;
  while(l < r) {
    int mid = l + (r - l) / 2;
//    deb(mid);
    if(check(mid)) r = mid - 1;
    else l = mid + 1;
  }
  cout << l << '\n';
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
