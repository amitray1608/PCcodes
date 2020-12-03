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
  vector<pair<int, int>> a(n);
  map<int, int> ind;
  set<int> st;
  for(auto &i : a) {
    cin >> i.first >> i.second;
    st.insert(i.first);
    st.insert(i.second);
  }
  int id = 0;
  for(int i : st)
    ind[i] = id++;
  vector<int> ans(st.size(), 0);
  auto cmp = [&](const pair<int, int> &x, const pair<int, int> &y) {
      return x.second < y.second;
  };
  sort(a.begin(), a.end(), cmp);
  for(int i = 0; i < n; i++) {
    int sid = ind[a[i].first], eid = ind[a[i].second];
    ans[sid]++, ans[eid]--;
  }
  for(int i = 1; i < st.size(); i++) {
//    cout << ans[i] << ' ';
    ans[i] += ans[i-1];
  }
  cout << *max_element(ans.begin(), ans.end()) << endl;
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
