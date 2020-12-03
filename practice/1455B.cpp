#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve(){
  int n;
  cin >> n;
  int x = 0, sum = 0;
  while(sum < n) {
    x++;
    sum += x;
  }
  cout << (x + (sum - n == 1 ? 1 : 0)) << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
  //  cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
