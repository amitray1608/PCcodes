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
  std::vector<int> a(n, 0); 
  for(int &i : a) {
    cin >> i;
    if(i < 0)
      i = 0;
    else
      i = 1;
  }
  std::vector<int> pre(n, 0);
  int turn = a[n-1];
  pre[n-1] = 1;
  for(int i = n-2; i >= 0; i--){
    if(turn){
      if(a[i] == 0) 
        pre[i] += pre[i+1]+1, turn = 0;
      else
        pre[i] = 1, turn = a[i];
    }else{
      if(a[i] == 1) 
        pre[i] += pre[i+1]+1, turn = 1;
      else
        pre[i] = 1, turn = a[i];
    }
  }
  for(int ii : pre)
      cout << ii << ' ';
  cout << endl;
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