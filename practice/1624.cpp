#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;

const int MAXN = 64;
int col[MAXN], diag1[MAXN], diag2[MAXN];

vector<string> s(8);
int ans = 0, n = 8;

void recc(int y) {
  if(y == n) {
    ans++;
    return;
  }
  for(int x = 0; x < n; x++) {
    if(s[x][y] == '*') continue;
    if(col[x] or diag1[x+y] or diag2[x-y+n-1]) continue;
    col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
    recc(y+1);
    col[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
  }
}

void solve(){
  for(int i = 0; i < n; i++)
    cin >> s[i];
  recc(0);
  cout << ans;
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
