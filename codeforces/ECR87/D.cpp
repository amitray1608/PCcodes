//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll siz = 1e6 + 5;
const ll MOD = 1e9 + 7;
// #define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
ll a[200005];

struct node {
	ll s1, s2;
}tree[800005];

void build(ll p, ll s, ll e) {
    if (s > e) {
        return;
    }
    if (s == e) {
        ll pr;
        s & 1? pr = -1: pr = 1;
        tree[p].s1 = pr * a[s];
        tree[p].s2 = pr * a[s] * (s + 1);
        return;
    }
    ll m = (s + e) >> 1;
    build(p << 1, s, m);
    build((p << 1) | 1, m + 1, e);
	tree[p].s1 = tree[p << 1].s1 + tree[(p << 1) | 1].s1;
	tree[p].s2 = tree[p << 1].s2 + tree[(p << 1) | 1].s2;
}
void update(ll p, ll s, ll e, ll l, ll val) {
    if (l > e or l < s or s > e) {
        return;
    }
    if (s == e and l == s) {
        ll pr;
        s & 1? pr = -1: pr = 1;
		tree[p].s1 = pr * val;
		tree[p].s2 = pr * val * (s + 1);
        return;
    }
    ll m = (s + e) >> 1;
    if (l <= m) {
        update(p << 1, s, m, l, val);
    }
    else {
        update((p << 1) | 1, m + 1, e, l, val);
    }
	tree[p].s1 = tree[p << 1].s1 + tree[(p << 1) | 1].s1;
	tree[p].s2 = tree[p << 1].s2 + tree[(p << 1) | 1].s2;
}
node query(ll p, ll s, ll e, ll l, ll u) {
	node res;
	res.s1 = 0;
	res.s2 = 0;
    if (l > e or s > u) {
        return res;
    }
    if (l <= s and u >= e) {
        return tree[p];
    }
    ll m = (s + e) >> 1;
    if (e <= m) {
        return query(p << 1, s, m, l, u);
    }
    if (s > m) {
        return query((p	 << 1) | 1, m + 1, e, l, u);
    }
    node res1, res2;
    res1 = query(p << 1, s, m, l, u);
    res2 = query((p << 1) | 1, m + 1, e, l, u);
    res.s1 = res1.s1 + res2.s1;
    res.s2 = res1.s2 + res2.s2;
    return res;
}
void solve(){
    ll n, q;
    cin >> n >> q;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    //for(int i = 1; i < 10; i++)
		//cout << tree[i].s1 << " ";
	//cout << endl;
    //for(int i = 1; i < 10; i++)
		//cout << tree[i].s2 << " ";
	//cout << endl;
    ll res(0);
    while (q--) {
        char x;
        ll l, u;
        cin >> x >> l >> u;
        if (x == 'U') {
            update(1, 0, n - 1, l - 1, u);
        }
        else {
            node sol = query(1, 0, n - 1, l - 1, u - 1);
            ll check = l - 1, r = -1;
            if (l & 1) {
                r = 1;
            }
            ll rr = sol.s2 - (check * sol.s1);
            rr *= r;
            res += rr;
            cout << rr << endl;
        }
    }
    cout << res << "\n";
}

signed main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 0;
		cin >> t;
		for(ll i = 1; i <= t; i++){
			cout << "Case #" << i <<": ";
			solve();
		}
	return 0;
}
