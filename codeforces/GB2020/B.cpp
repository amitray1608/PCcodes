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
  set<int> st;
  for(int &i : a) cin >> i;
  int count = 1;
  for(int i = 1; i < n; i++) {
    if(i == n - 1) {
      if(a[i] == a[i - 1]) a[i]++;
    }
    if(a[i] == a[i - 1]) {
      if(a[i] == a[i + 1]) continue;
      else a[i]++;
    }
  }
  for(int i : a) st.insert(i);
  cout << st.size() << '\n';
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
