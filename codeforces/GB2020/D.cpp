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
  multiset<int>mt;
  vector<int> in(n, 0), a(n, 0);
  for(int &i : a) cin >> i;
  ll sum = accumulate(a.begin(), a.end(), 0);
  for(int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v; u--, v--;
    in[u]++, in[v]++;
    if(in[u] > 1) mt.insert(a[u]);
    if(in[v] > 1) mt.insert(a[v]);
  }
  cout << sum << ' ';
  vector<int> rev;
  for(auto i : mt) rev.push_back(i);
  reverse(rev.begin(), rev.end());
  for(auto i : rev) {
//    deb(i);
    sum += i;
    cout << sum << ' ';
  }
  cout << endl;
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
