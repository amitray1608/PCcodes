//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
int n, c;
bool fun(int x, int a[]){
	int cc = 1, pos = a[0];
	for(int i = 1; i < n; i++){
		if(a[i]-pos >= x){
			pos = a[i];
			cc++;
			if(c == cc)
				return true;
		}
	}
	return false;
}
void solve(){
	cin >> n >> c;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	int l = a[0], h = a[n-1], maxi = -1;
	while(l < h){
		int mid = (l+h)/2;
		if(fun(mid, a)){
			if(mid > maxi)
				maxi = mid;
			l = mid+1;
		}else{
			h = mid;
		}
	}
	cout << maxi << endl;
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
