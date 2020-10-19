#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
vector<ll>BIT, a;
ll n;
 
ll sum(ll index) {
	ll s = 0;
	while(index > 0) {
		s += BIT[index];
		index -= index&(-index);
	}
	return s;
}
 
void update(ll index, ll val) {
	while(index <= n) {
		BIT[index] += val;
		index += index&(-index);
	}
}
 
void convert() {
	vector<ll>tmp = a;
	sort(tmp.begin(), tmp.end());
	for(ll i = 0; i < n; i++) {
		a[i] = lower_bound(tmp.begin(), tmp.end(), a[i]) - tmp.begin() + 1;
	}
}
 
int main() {
	ios::sync_with_stdio(false);
	// cin.tie(NULL);
	ll t;
	cin >> t;
	while(t--) {
		cin >> n;
		a.resize(n, 0);
		BIT.resize(n+1, 0);
		for(ll i = 0; i < n; i++) cin >> a[i];
		convert();
		ll count = 0;
		for(ll i =  n-1; i >= 0; i--) {
			count += sum(a[i] - 1);
			update(a[i], 1);
		}
    int total = (n*(n-1))/2 - 1;
    if(count <= total)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
        BIT.clear();
	}
} 
