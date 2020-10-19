//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

void solve(){
  int n;
  cin >> n;
  std::vector<int> v(n);
  for(int &i : v) cin >> i;
  bool flag = true;
  long amt = 0;
  for(int i = 0; i < n; i++){
    if(i == 0){
      if(v[i] != 5){
        flag = false;
        break;
      }
    }
    if(v[i] == 5){
      amt += 5;
    }else if(v[i] - 5 <= amt){
      amt -= (v[i]-5);
    }else{
      flag = false;
      break;
    }
  }
  cout << (flag ? "YES" : "NO") << endl;
}

int main(){
  #ifndef RAY
    //freopen("input.txt", "r", stdin);
  #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
      solve();
    }
  return 0;
}  

ra