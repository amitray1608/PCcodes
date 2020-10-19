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
  int n;
  cin >> n;
  vector<int> e;
  vector<int> o;
  vector<int> a(2*n+1);
  for(int i = 1; i <= 2*n; i++){
    // int x;
    cin >> a[i];
    if(~a[i]&1)
        e.push_back(i);
    else
        o.push_back(i);
  }
  // int E = (int)e.size(), O = (int)o.size();
  // if(E%2 == 0 and O%2 == 0){
  //   for(int i = 0; i < E-2; i += 2){
  //       cout << e[i] << " " << e[i+1] << endl;
  //       deb(i);
  //       deb(i+1)
  //   }
  //   for(int i = 0;i < O; i += 2){
  //       cout << o[i] << " " << o[i+1] << endl;
  //       deb(i);
  //       deb(i+1);
  //   }
  // } else {
  //   for(int i = 0; i < E-2; i += 2){
  //       cout << e[i] << " " << e[i+1] << endl;
  //               deb(i);
  //       deb(i+1);
  //   }
  //   for(int i = 0; i < O-2; i += 2){
  //       cout << o[i] << " " << o[i+1] << endl;
  //               deb(i);
  //       deb(i+1);
  //   }
  // } 
  int count = 0 ;
  for(int i = 1; i <= n*2; i++) {
    if(count == n-1){
      break;
    }
    if(a[i] == -1){
      continue;
    }
    for(int j = 1; j <= 2*n; j++) {
      if(a[j] != -1 and j!= i) {
        if(~(a[i] + a[j]) & 1) {
          count++;
          cout << i << ' ' << j << endl;
          a[i] = a[j]  = -1;
          break;
        }
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  