//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
vector<int>tree(120000);


void update(int node, int s, int e, int i){
	if(s == e and s == i){
		tree[node] = 1;
		return;
	}
	int mid = (s+e) >> 1;
	if(i <= mid)
		update(node << 1,  s, mid, i);
	else
		update((node << 1) | 1, mid+1, e, i);
	tree[mid] = tree[node << 1] + tree[(node << 1) | 1];
}

int query(int node, int s, int e, int l, int r){
	if(s > l or e < r)
		return 0;
	if(l <= s and r >= e)
		return tree[node];
	int mid = (s+e) >> 1;
	if(r <= mid)
		return query(node << 1, s, mid, l, r);
	else if(l >= mid)
		return query((node << 1) | 1, mid+1, e, l, r);
	return query(node << 1, s, mid, l, r) + query((node << 1) | 1, mid+1, e, l, r);
}

void solve(){
	int n;
	cin >> n;
	vector<pair<int, int>>a;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a.push_back({x, i});
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	//for(auto i : a){
		//cout << i.first << " " << i.second << endl;
	//}
	cout << "Query" << endl;
	int q;
	cin >> q;
	int j = 0;
	vector<pair<int, pair<int, pair<int, int>>>>quer;
	while(j < q){
		int x, y, k;
		cin >> x >> y >> k;
		quer.push_back({k, {j, {x, y}}});
		j++;
	}
	sort(quer.begin(), quer.end());
	reverse(quer.begin(), quer.end());
	for(auto i : quer){
		cout << i.first  << " " << i.second.first << " " << i.second.first << endl;
	}
	vector<int>ans(q, 0);
	j = 0;
	int i = 0;
	while(i < q){
		int pos = quer[i].second.first;
		int l = quer[i].second.second.first;
		int r = quer[i].second.second.second;
		int k = quer[i].first;
		while(j < n and a[j].first > k){
			update(1, 0, n-1, a[j].second);
			j++;
		}
		ans[pos] = query(1, 0, n-1, l-1, r-1);
		i++;
	}
	for(int &ii : ans)
		cout << ii << endl;
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
