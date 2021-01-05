#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

void solve() {
  int n; cin >> n;
  string a, b;
  cin >> a >> b;
  int red = 0, blue = 0, same = 0;
  for(int i = 0; i < n; i++) {
    if(a[i] == b[i]) same++;
    else if(a[i] > b[i]) red++;
    else blue++;
  }
  if(same == n or (red == blue and red + blue + same == n)) {
    cout << "EQUAL" << endl;
  } else if(red > blue) {
    cout << "RED" << endl;
  } else {
    cout << "BLUE" << endl;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
