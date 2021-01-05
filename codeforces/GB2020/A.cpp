#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int &i : a) cin >> i;
  set<double> ans;
  for(int i = 0; i < n; i++) {
    for(int j = i + 1; j < n; j++) {
      double x1 = a[i], y1 = 0, x2 = a[j],  y2 = 0, x3 = 0, y3 = 1;
      double area = 0.5 * (x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
      ans.insert(area);
    }
  }
  cout << ans.size() << '\n';
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
