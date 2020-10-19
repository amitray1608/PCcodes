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
  string s;
  cin >> s;
  std::vector<int> v;
  for(char c : s) {
    if(c == '+')
      continue;
    v.push_back(c-'0');
  }
  sort(v.begin(), v.end());
  int n = (int)v.size();
  for(int i = 0; i < n; i++){
    cout << v[i];
    if(i == n-1) continue;
    cout << '+';
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  