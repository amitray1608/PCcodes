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
  int a[n];
  for(int &i : a) cin >> i;
  std::vector<int> v;
  v.push_back(a[0]);
  int i = 0;
  while(i < n-1){
    if(a[i+1] < a[i]){
      while(a[i+1] < a[i] and i < n-1) i++;
          v.push_back(a[i]);
    }else{
      while(a[i+1] > a[i] and i < n-1) i++;
          v.push_back(a[i]);
    }
  }
  cout << v.size() << endl;
  for(int x : v)
      cout << x << ' ';
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