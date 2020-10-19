//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

int digsum(int n){
  int sum = 0;
  while(n > 0){
    sum += n%10;
    n/=10;
  }
  return sum;
}

void solve(){
  int n;
  cin >> n;
  int counta = 0, countb = 0;
  for(int i = 0; i < n; i++){
    int a, b;
    cin >> a >> b;
    a = digsum(a);
    b = digsum(b);
    if(a > b)
      counta++;
    else if(a < b)
      countb++;
    else
      countb++, counta++;
  }
  if(counta > countb){
    cout << 0 << ' ' << counta << endl;
  } else if(countb > counta){
    cout << 1 << ' ' << countb << endl;
  }else{
    cout << 2 << ' ' << countb << endl;
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