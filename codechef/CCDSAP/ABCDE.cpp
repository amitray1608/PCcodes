//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int &i : a) cin >> i;
	sort(a, a+n);
	ll count = 0LL;
	vector<int>x, y;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				int lhs = (a[i]*a[j])+a[k];
				x.push_back(lhs);
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				if(x[k] == 0) continue;
				int rhs = ((a[i]+a[j])*a[k]);
				y.push_back(rhs);
			}
		}
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	for(int i = 0; i < (int) x.size(); i++){
		int lo = lower_bound(y.begin(), y.end(), x[i])-y.begin();
		int ho = upper_bound(y.begin(), y.end(), x[i])-y.begin();
		count+=(ho-lo);
	}
	cout << count << endl;
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
