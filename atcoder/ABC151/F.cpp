//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
dd dist(dd a, dd b) {
	return (a*a + b*b);
}
void solve(){
	int n;
	cin >> n;
	dd X = 0, Y = 0, d, e, P = 0.1;
	vector<pair<double, double> > a(n);
	for(int i = 0; i < n; ++i){ 
		cin >> a[i].first >> a[i].second;
		X += a[i].first; Y += a[i].second;
	}
	X /= n; 
	Y /= n;
	for (int i = 0; i < 30000; i++) {
		int f = 0;
		d = dist(X - a[0].first, Y - a[0].second);
		for (int j = 1; j < n; j++) {
			e = dist(X - a[j].first, Y - a[j].second);
			if (d < e) { 
				d = e;
				 f = j; 
				}
		}
		X += (a[f].first - X)*P;
		Y += (a[f].second - Y)*P;
		P *= 0.999;
	}
	cout << sqrt(d) << endl;
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
				cout << fixed << setprecision(15);
			solve();
		}
	return 0;
}
	
