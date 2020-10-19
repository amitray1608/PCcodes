#include<bits/stdc++.h>
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
using namespace std;
typedef long long ll;
typedef long double dd;
const int MOD = 1e9 + 7;

const int MAXN = 101;
ll sum[MAXN][MAXN] = 0, counts = 0, total = 0;

void recc(int l, int r, vector<int> &a, int curr) {
  if (l == r) {
    total += curr;
    return;
  }
  for (int i = l; i != r; i++)
    solve(l, i), solve(i+1, r, a, curr + a[i+1]);
}
void solve(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(ll &i : a) cin >> i;
  recc(0, n-1, a, 0);
  sum /= 2;
  double c; 
  deb(sum);
  deb(counts);
  sum = 0;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  cin >> t;
  while(t--){
  cout << "Case #" << ++tt << ": ";
    solve();
  }
  return 0;
}//Hajimemashite
