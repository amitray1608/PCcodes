#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

#define N 200001
#define A 1000001
#define BLOCK 450
 
ll cnt[A], ans[N];
ll answer = 0, curr[A];
ll n, q;
vector<ll>a(N);

struct Node {
  ll l, r, i;
}qr[N];

bool compare(Node p, Node q) {
  if (p.l / BLOCK != q.l / BLOCK)
      return p.l < q.l;
  return (p.l / BLOCK & 1) ? (p.r < q.r) : (p.r > q.r);
}

void add(ll p) {
  cnt[a[p]]++;
  if(cnt[a[p]] >= 1) {
    answer -= curr[a[p]];
    ll x = cnt[a[p]] * cnt[a[p]] * a[p];
    answer += x;
    curr[a[p]] = x;
  }
}

void remove(ll p) {
  cnt[a[p]]--;
  if(cnt[a[p]] == 0) {
    answer -= curr[a[p]];
    curr[a[p]] = 0;
  } else {
    answer -= curr[a[p]];
    ll x = cnt[a[p]] * cnt[a[p]] * a[p];
    answer += x;
    curr[a[p]] = x;
  }
}

//s - 2sk;
void solve(){
  cin >> n >> q;
  for(ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(ll i = 0; i < q; i++) {
    cin >> qr[i].l >> qr[i].r;
    qr[i].i = i;
    qr[i].l--, qr[i].r--;
  }
  sort(qr, qr+q, compare);
  
  ll currL = 0, currR = 0;
  for(ll i = 0; i < q; i++) {
    ll L = qr[i].l, R = qr[i].r;
    while(currL > L) {
      add(currL-1);
      currL--;
    }
    while(currR <= R) {
      add(currR);
      currR++;
    } 
    while(currL < L) {
      remove(currL);
      currL++;
    }

    while(currR > R+1) {
      remove(currR-1);
      currR--;
    }
    ans[qr[i].i] = answer;
  }
  for(ll i = 0; i < q; i++)
    cout << ans[i] << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1, tt = 0;
  //cin >> t;
  while(t--){
    //tt++;
    //cout << "Case #" << t << ": ";
    solve();
  }
  return 0;
}
