//“checkke it work, checkke it right, checkke it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

vector<int> check;

// void recc(ll n) {

// }

bool isPrime(ll n){
  for(ll i = 2; i*i <= n; i++) {
    if(n%i == 0)
      return false;
  }
  return true;
}

void solve(){
  ll n;
  cin >> n;
  if (n == 1) 
    cout << "FastestFinger" << endl;
  else if (n == 2) 
    cout << "Ashishgup" << endl;
  else if(n&1)
    cout << "Ashishgup" << endl;
  else if(isPrime(n/2))
    cout << "FastestFinger" << endl;
  else if(ceil((double)log2(n)) == floor((double)log2(n))) 
    cout << "FastestFinger" << endl;
  else 
    cout << "Ashishgup" << endl;
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