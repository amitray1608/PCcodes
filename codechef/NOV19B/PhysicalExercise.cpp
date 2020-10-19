//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
double Line(ll x, ll y, ll x1, ll y1){
	return (double)(1.0*sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1)));
}

void solve(){
		ll x, y, n, m, k;
		cin >> x >> y;
		cin >> n >> m >> k;
		double A[n][3], B[m][3], C[k][3];
		for(ll i=0; i<n; i++) cin >> A[i][0] >> A[i][1], A[i][2] = LONG_MAX;

		for(ll i=0; i<m; i++) cin >> B[i][0] >> B[i][1], B[i][2] = LONG_MAX;
		
		for(ll i=0; i<k; i++) cin >> C[i][0] >> C[i][1];




		for(ll i = 0; i<n; i++){
			for(ll j = 0; j <k; j++){
				double tmp = Line(A[i][0], A[i][1], C[j][0], C[j][1]);
				if(A[i][2] > tmp) A[i][2] = tmp;
			}
		}
		for(ll i = 0; i<m; i++){
			for(ll j = 0; j <k; j++){
				double tmp = Line(B[i][0], B[i][1], C[j][0], C[j][1]);
				if(B[i][2] > tmp) B[i][2] = tmp;
			}
		}
		double mini = LONG_MAX;
		for(ll i = 0; i<n; i++){
			double tmp = Line(x, y, A[i][0], A[i][1]);
			for(ll j = 0; j <m; j++){
				double tmp2 =  Line(A[i][0], A[i][1], B[j][0], B[j][1]);
				if(tmp+tmp2+B[j][2] < mini) mini = tmp+tmp2+B[j][2];
			}
		}
		for(ll i = 0; i<m; i++){
			double tmp = Line(x, y, B[i][0], B[i][1]);
			for(ll j = 0; j <n; j++){
				double tmp2 =  Line(A[j][0], A[j][1], B[i][0], B[i][1]);
				if(tmp+tmp2+A[j][2] < mini) mini = tmp+tmp2+A[j][2];
			}
		}
	cout << mini << endl;
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
			 cout << fixed << setprecision(12);
			solve();
		}
	return 0;
}
