//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e5 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

pair<int, int>tree[siz*4];

pair<int, int>merge(pair<int, int>a, pair<int, int>b) {
  priority_queue<int>q;
  q.push(a.first);
  q.push(a.second);
  q.push(b.first);
  q.push(b.second);
  pair<int, int>ans;
  ans.first = q.top();
  q.pop();
  ans.second = q.top();
  return ans;
}

void update(int n, int s, int e, int p, int val) {
  if(s > e)
      return;
  if(s == p and e == p) {
    // cout << "AT " << p << ' ' << val << endl;
    tree[n] = {val, -1};
    return;
  }
  int mid = (s+e) >> 1;
  if(p <= mid)
    update(n+n, s, mid, p, val);
  else
    update(n+n+1, mid+1, e, p, val);
  tree[n] = merge(tree[n+n], tree[n+n+1]);
}

pair<int, int> query(int n, int s, int e, int l, int r) {
  pair<int, int>x = {0, 0};
  if(s > e or s > r or e < l) return x;
  if(s >= l and e <= r)
      return tree[n];
  int mid = (s+e) >> 1;
  query(n+n, s, mid, l, r);
  query(n+n+1, mid+1, e, l, r);
  return merge(query(n+n, s, mid, l, r), query(n+n+1, mid+1, e, l, r));
}
void solve(){
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int x;
    cin >> x;
    update(1, 0, n-1, i, x);
  }
  // for(int i = 1; i < 12; i++) {
  //   cout << "{" << tree[i].first << ',' << tree[i].second << "}" << ' ';
  // }
  int q;
  cin >> q;
  while(q--) {
   char c;
   cin >> c;
   int l, r;
   cin >> l >> r;
   if(c == 'Q') {
     l--, r--;
     pair<int, int>ans = query(1, 0, n-1, l, r);
     cout << ans.first + ans.second << endl;
   } else {
     l--;
     update(1, 0, n-1, l, r);
   }
  }
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