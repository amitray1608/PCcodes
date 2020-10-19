//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 50001;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

struct seg{
	int pre, suf, maxi, total;
}tree[siz << 3];

seg merge(seg a, seg b){
	seg ans;
	ans.total = a.total + b.total;
	ans.pre = max(a.pre, a.total+b.pre);
	ans.suf = max(b.suf, b.total+a.suf);
	ans.maxi = max(max(a.maxi, b.maxi), (a.suf+b.pre));
	return ans;
}

void build(int node, int s, int e){
	if(s == e){
		int x;
		cin >> x;
		tree[node].maxi = tree[node].pre = tree[node].suf = tree[node].total = x;
		return; 
	}
	int l = node << 1;
	int r = node << 1 | 1;
	int mid = (s+e) >> 1;
	build(l, s, mid);
	build(r, mid+1, e);
	tree[node] = merge(tree[l], tree[r]); 
}
seg query(int node, int s, int e, int x, int y){
	if(s == x and e == y)
		return tree[node];
	int l = node << 1;
	int r = node << 1 | 1;
	int mid = (s+e) >> 1;
	if(y <= mid)
		return query(l, s, mid, x, y);
	else if(x > mid)
		return query(r, mid+1, e, x, y);
	else
		return merge(query(l, s, mid, x, mid), query(r, mid+1, e, mid+1, y));
}

void solve(){
	int n;
	cin >> n;
	build(1, 1, n);
	int q;
	cin >> q;
	while(q--){
		int x, y;
		cin >> x >> y;
		cout << query(1, 1, n, x, y).maxi << endl;
	}
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		//cin >> t;
		while(t--){
			solve();
		}
	return 0;
}	
