#include<bits/stdc++.h>

using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;


char* bitwise(int input) {
  int count = 0, lsb = -1, msb = -1, pos = 0;
  while(input) {
    int rem = input % 2;
    if(lsb == -1 and rem == 1)
      lsb = pos;
    if(rem == 1)
      msb = pos;
    input /= 2;
    if(rem == 1) count++;
    pos++;
  }
  if(lsb == -1) lsb = 0;
  if(msb == -1) msb = 0;
  char ans[6];
  ans[0] = (char)(count + '0');
  ans[1] = '#';
  ans[2] = (char)(lsb + '0');
  ans[3] = '#';
  ans[4] = (char)(msb + '0');
  ans[5] = '\0';
  char *s = &ans[0];
  return s;
}

void solve() {
  int n;
  cin >> n;
  char *s = bitwise(n);
  cout << s << '\n';
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
} //Hajimemashite
