//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e5 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

int tree[siz*4];

void update(int n, int s, int e, int p, int val) {
  if(s > e)
      return;
  if(s == e and e == p) {
    tree[n] = val;
    return;
  }
  int mid = (s+e) >> 1;
  if(p <= mid)
    update(n+n, s, mid, p, val);
  else
    update(n+n+1, mid+1, p, val);
  tree[n] = tree[n+n+1] + tree[n+n];
} 



void solve(){
  int n;
  cin >> n;

}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << tt << ": ";
    solve();
  }
  return 0;
}  