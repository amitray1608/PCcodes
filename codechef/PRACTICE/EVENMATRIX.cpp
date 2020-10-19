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
  vector<int> v[n];
  vector<int> tmp;
  int count = 0, status = 0;
  for(int i = 0; i < n; i++){
    tmp.clear();
    for(int j = 0; j < n ; j++){
      count++;
      tmp.push_back(count);
    }
    if(status){
      reverse(tmp.begin(), tmp.end());
      v[i] = tmp;
    }else{
      v[i] = tmp;
    }
    status ^= 1;
  }
  for(int i = 0; i < n; i++){
    for(int j : v[i])
        cout << j << ' ';
    cout << endl;
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