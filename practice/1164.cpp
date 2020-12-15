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
  set<int> st;
  multiset<int> room;
  for(auto &i : a) cin >> i.first >> i.second, st.insert(i.first), st.insert(i.second);
  
  map<int, int>mp, alloc;
  int j = 0, k = 1;
  for(int i : st) {
    alloc[a[i].first] = k;
    alloc[a[i].second] = -k;
    mp[a[i].first] = j++;
    mp[a[i].second] = j++;
    k++;
  }
  vector<int>pre(j, 0), ans(n, 0);
  for(auto i : alloc) {
    if(
  }
  for(int i = 0; i < n; i++) {
    pre[mp[a[i].first]]++;
    pre[mp[a[i].second] + 1]--;
  }
  for(int i = 1; i < j; i++) {
    pre[i] += pre[i - 1];
  }

  int maxi = 0;
  for(auto i : pre) 
    maxi = max(maxi, i);
  cout << maxi << '\n';
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
