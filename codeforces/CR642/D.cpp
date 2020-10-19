//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(mid) cout << #mid << " = " << mid << endl;
int ans[siz];
void rec(int l, int r, int count){
	if(l > r){
		//ans[l] = count++;
		return;
	}
	int mid = (l+r)/2;
	ans[mid] = count++;
	if(mid - l > mid - r)
		 return rec(l, mid, count+1);
	else
		 return rec(mid, r, count+1);
}

void solve(){
	int n;
	cin >> n;
	int a[n+1], i = 1;
	//memset(ans, 0, sizeof ans);
	memset(a, 0, sizeof a);
	// queue<pair<int,int>> q;
	// q.push({0, n - 1});
	set<pair<ll, pair<ll,ll> > > curr;
	curr.insert({-n, {1, n}});
	while(curr.size()){
		pair<ll,pair<ll,ll> > tmp = *curr.begin();
		ll l = tmp.second.first;
		ll r = tmp.second.second;
		curr.erase(tmp);
		if(l > r) continue;
		if(l == r){
			a[l] = i++;
			continue;
		}
		int mid = r-l+1;
		if(mid&1){
			a[(l+r)/2] = i++;
			mid = (l+r)/2;
			curr.insert({-(mid-l), {l, mid-1}});
			curr.insert({-(r-mid), {mid+1,r}});
		}
		else{
			a[(l+r-1)/2] = i++;
			mid = (l+r-1)/2;
			curr.insert({-(mid-l), {l, mid-1}});
			curr.insert({-(r-mid), {mid+1, r}});
		}
	}
	for(i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << "\n";
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		while(t--){
			solve();
		}
	return 0;
}	
	
