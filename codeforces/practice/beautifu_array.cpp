/*RAY header for competition*/
#include <bits/stdc++.h> 
using namespace std;
typedef int  ll;
void solve(){
	ll n, x;
	cin >> n >> x;
	ll X[n+1];
	for(ll i=0; i<n; i++)
        cin >> X[i], X[i] *= x;
	ll curr = 0, maxi = 0;
	for(ll i = 0; i<n; i++)
	 {
		 curr += X[i];
		 if(curr > maxi)
            maxi = curr;
        
        if(curr < 0)
        curr = 0;
	 }
	 cout << maxi << endl;
}
int main() {
ios::sync_with_stdio(false); 
#ifdef RAY
  freopen("input.txt" , "r" , stdin);
#endif
ll t = 1;
//cin >> c;
while(t--){
        solve();
}
#ifdef RAY
  cerr<<"Time Elapsed "<<(double)clock()/CLOCKS_PER_SEC <<" s\n";
#endif
}
