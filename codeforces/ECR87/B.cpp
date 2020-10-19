//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
 #define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;
bool isPerfectSquare(double x) {    
  double sr = sqrt(x); 
	return ((sr - floor(sr)) == 0); 
} 
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int &i : a) cin >> i;
	ll count = 0, sqr = 0;
	for(int i = 0; i < n; i++){
		sqr = 0;
		for(int j = i; j < n; j++){
			sqr += a[j];
			if(isPerfectSquare((double)sqr))
				count++;
		}
	}
	cout << count << endl;
}

int main(){
	#ifndef RAY
		//freopen("input.txt", "r", stdin);
	#endif
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 0;
		cin >> t;
		for(int i = 1; i <= t; i++){
			cout << "Case #" << i <<": ";
			solve();
		}
	return 0;
}	
