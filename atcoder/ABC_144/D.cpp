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
	double a,b,v;
	cin>>a>>b>>v;
	double ans=0;
	if(a*a*b/2<=v){
		double y=2*(a*a*b-v);
		double x=a*a*a;
		ans=atan2(y,x);
	}
	else{
		double y=b*b*a;
		double x=2*v;
		ans=atan2(y,x);
	}
	cout <<ans*360/(2*M_PI);
}

int main(){
	#ifndef RAY
		freopen("input.txt", "r", stdin);
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
	
