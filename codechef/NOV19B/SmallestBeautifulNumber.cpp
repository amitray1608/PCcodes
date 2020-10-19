//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define endl '\n'
#define deb(x) cout << #x << " = " << x << endl;

bool isPerfectSquare(double x) 
{   

  double sr = sqrt(x); 
  
  return ((sr - floor(sr)) == 0); 
} 

void solve(){
	int n;
	cin >> n;
	double i = pow(10, n-1);
	bool x = false;
	while(i < pow(10, n)){
		ll tmp = i;
		//cout << i << endl;
		double sum  = 0.0;
		bool flag = true;
		while(tmp > 0){
			if(tmp % 10 == 0){ flag = false; break;}
			ll x = tmp%10;
			sum += ( x*x );
			 tmp /= 10;
		} 
		
		if(flag){
			//deb(sum);
			if(isPerfectSquare(sum)){
				cout << i << endl;
				x = true;
			}
		}
		if(x){break;}
		i++;
	}
	if(!x) cout << -1 << endl;
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
