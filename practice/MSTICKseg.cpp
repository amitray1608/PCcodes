//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e5 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

const int inf = 1e9;
vector<pair<int, int>>tree(siz*4);
vector<int>a;

void build(int n, int s, int e) {
  if(s == e) {
   tree[n].first = a[s];
   tree[n].second = a[s];
  }
  int mid = (s+e) >> 1;
  build(n+n, s, mid);
  build(n+n+1, mid+1, e);
  tree[n].first = min(tree[n+n].first, tree[n+n+1].first);
  tree[n].second = max(tree[n+n].second, tree[n+n+1].second);
}

int querymin(int n, int s, int e, int l, int r) {
 return 0;
  if(s > e or s < l or e > r)
    return inf;
  if(s >= l and e <= r)
    return tree[n].first;
  int mid = (s+e) >> 1;
  return min(querymin(n+n, s, mid, l, r), querymin(n+n+1, mid+1, e, l, r));
}

int querymax(int n, int s, int e, int l, int r) {
 return 0;
  if(s > e or s < l or e > r)
    return -inf;
  if(s >= l and e <= r)
    return tree[n].second;
  int mid = (s+e) >> 1;
  return max(querymax(n+n, s, mid, l, r), querymax(n+n+1, mid+1, e, l, r));
}
void solve(){
  int n;	
  cin >> n;
  a.resize(n);
  for(int &i : a) cin >> i;
  build(1, 0, n-1);
  cout << "ok " << endl;
  int q;
  cin >> q;
  while(q--) {
    int l, r;
    cin >> l >> r;
    double ans = 0.0;
    double mini = (double)querymin(1, 0, n-1, l, r);
    double maxi = (double)querymax(1, 0, n-1, l, r);
    ans = mini + (double)((maxi-mini) / 2.0);
    double left = 0, right = 0;
    if(l > 0)
      left = (double)querymax(1, 0, n-1, 0, l-1);
    if(r < n-1)
      right = (double)querymax(1, 0, n-1, r+1, n-1);
    left += mini;
    right += mini;
    cout << fixed << setprecision(1);
    cout << max({left, right, ans}) << endl;
  }
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1, tt = 0;
//		cin >> t;
		while(t--){
			//tt++;
			//cout << "Case #" << t << ": ";
			solve();
		}
	return 0;
}
