//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
  int n, q;
  cin >> n >> q;
  vector<int>a(n-1);
  for(int &i : a) cin >> i;
  while(q--){
    int s, k;
    cin >> s >> k;
    k--, s--;
    vector<int>ans;
    ans.push_back(s);
    if(a[s+1] > a[s-1]) {
      if(s-1 >= 0)
        ans.push_back(s-1);
      for(int i = s+1; i < n; i++)
      ans.push_back(i);
     for(int i = s-2; i >= 0; i--)
      ans.push_back(i);
    } else {
      if(s+1 <= n-1)
        ans.push_back(s+1);
      for(int i = s-2; i >= 0; i--){
      ans.push_back(i);
      }
      for(int i = s+2; i < n; i++){
        ans.push_back(i);  
      }
    }
    // cout << endl;
    // for(int &i : ans)
    //   cout << i << ' ';
    // cout << endl;
    cout << ans[k]+1 << ' ';
  }
  cout << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    tt++;
    cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  