#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve(){
  int n, m;
  cin >> n >> m;
  multiset<int> st;
  map<int, int> freq;
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    st.insert(x);
    freq[x]++;
  }
  vector<int> ans(m, -1);
  for(int i = 0; i < m; i++) {
    int x; cin >> x;
    cout << x << " :  ";
    int have = *st.lower_bound(x);
    cout << have << endl;
    if(have <= x) {
      ans[i] = have;
      freq[have]--;
      if(freq[have] == 0) 
        st.erase(have);
     }
  }
  for(int i : ans) cout << i << ' ';
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
