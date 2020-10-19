#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

void solve(){
  int n;
  cin >> n;
  vector<int>a(n+1);
  for(int i = 0; i < n-1; i++) {
    int u, v;
    cin >> u >> v;
    a[v]++;
  }
  int count = 0;
  for(int i = 1; i < n + 1; i++) {
      count += max(a[i] - 1, 0);
  } 
  cout << count << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
  //cout << "Case #" << ++t << ": ";
    solve();
  }
  return 0;
}
