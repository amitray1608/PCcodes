#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define siz 10001
struct Node{
	ll pre, suf, total, maxi;
	Node () {
		pre = suf = total = maxi = 0;
	}
	void merge(Node a, Node b){
		pre = max(a.pre, a.total + b.pre);
		suf = max(b.suf, b.total + a.suf);
		total = a.total + b.total;
		maxi = max(pre, max(suf, max(a.suf+b.pre, max(total, max(a.maxi, b.maxi)))));	 
	};
}tree[10001 << 2];
 
void build(ll node, ll s, ll e, ll a[]){
	if(e < s)
		return;
	if(s == e){
		tree[node].pre= a[s];
		tree[node].suf = a[s];
		tree[node].total = a[s];
		tree[node].maxi = a[s];
		return;
	}
	ll mid = (s+e) >> 1;
	build(node << 1, s, mid, a);
	build((node << 1) | 1, mid+1, e, a);
	tree[node].merge(tree[node<<1], tree[(node<<1)|1]);
}
 
Node query(ll node, ll s, ll e, ll l, ll r){
	Node ans;
	if(l > r  or l > e or s > r)
		return ans;
	if(l <= s and r >= e) {
		return tree[node];
	}
	ll mid = (s+e) >> 1;
	if(r <= mid)
			return query(node << 1, s, mid, l, r);
	else if(l > mid)
			return query((node << 1) | 1, mid + 1, e, l, r);
	ans.merge(query(node << 1, s, mid, l, r), query((node << 1) | 1, mid + 1, e, l, r));
	return ans;
}
 
void solve() {
	ll n;
	cin >> n;
	ll a[n];
	for(ll &i : a) cin >> i;
	build(1, 0, n-1, a);
	ll q;
	cin >> q;
	while(q--){
		ll x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--;
		y1--;
		x2--;
		y2--;
		ll res = 0;
        if (x2 > y1) {
            Node r1 = query(1, 0, n - 1, x1, y1);
            Node r2 = query(1, 0, n - 1, x2, y2);
            Node r3 = query(1, 0, n - 1, y1 + 1, x2 - 1);
            res = r1.suf + r3.total + r2.pre;
        }
        else {
            Node r1 = query(1, 0, n - 1, x1, x2 - 1);
            Node r2 = query(1, 0, n - 1, y1 + 1, y2);
            Node r3 = query(1, 0, n - 1, x2, y1);
            res = max(r1.suf + r3.pre, max(r1.suf + r3.total + r2.pre, max(r2.pre + r3.suf, r3.maxi)));
		}
			cout << res << endl;
	}
	//for(int i = 0; i < n)
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t =1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
 
