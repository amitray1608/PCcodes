#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef double dd;
const int MOD = 1e9 + 7;

template<typename T>
string to_string(vector<T> v) {
  string res;
  for(auto &i : v)
    res += char('0'+i), res += ' ';
  return res;
}
 
template<class A> void vbug(A x) {
  cout << to_string(x) << endl;
}

void solve(){
  int n, m, k;
  cin >> n >> m >> k;
  vector<int>a(n);
  for(int &i : a) cin >> i;
  vector<int>x(n);
  x[0] = a[0];
  for(int i = 1; i < n; i++) 
    x[i] = x[i-1] ^ a[i];
  vbug(x);
  for(int i = 1; i < n; i++) {
    x[i] = x[i] ^ x[i-1];
  }
  vbug(x);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
