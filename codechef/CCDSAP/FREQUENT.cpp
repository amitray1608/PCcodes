//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
pair<int, int>tree[4*N+1];

pair<int, int>combine(pair<int, int>a, pair<int, int> b){
	if(a.second > b.second)
		return a;
	if(a.second <= b.second)
		return b;
	return make_pair(a.first, a.second+b.second);
}

void build(int a[], int v, int tl, int tr){
	if(tl == tr)
		tree[v] = make_pair(a[tl], 1);
	else{
		int mid = (tl + tr) >> 1;
		build(a, v<<1, tl, mid);
		build(a, (v<<1)+1, mid+1, tr);
		tree[v] = combine(tree[v<<1], tree[(v<<1)|1]);
	}
}
pair<int, int>query(int v, int tl, int tr, int l, int r){
	if(l > r)
		return make_pair(-MOD, 0);
	if(l == tl and r == tr)
		return tree[v];
	int mid = (tl+tr) >> 1;
	return combine(query(v<<1, tl, mid, l, min(mid, r)),
					query((v<<1)|1, mid+1, tr, max(l, mid+1), r));
}
void solve(){
	int n, q;
	cin >> n >> q;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	build(a, 0, 0, n-1);
	while(q--){
		int l, r;
		cin >> l;
		if(l == 0) continue;
		cin >> r;
		l--, r--;
		pair<int, int>ans = query(0, 0, n-1, l, r);
		cout << ans.second << endl;
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
	
