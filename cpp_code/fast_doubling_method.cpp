#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 1e9+7;
ll a, b, c, d;
void fast_fib(ll n, ll ans[]){
	if(n==0){
		ans[0] = 0;
		ans[1] = 1;
		return ;
	}

	fast_fib(n/2, ans);
	a = ans[0];
	b = ans[1];
	c = 2*b - a;
	if(c<0)
	c += MOD;
	
	c = (a*c) % MOD;
	d = (a*a + b*b) %MOD;
	
	if(n%2 == 0){
		ans[0] = c;
		ans[1] = d;
	}
	else{
		ans[0] = d;
		ans[1] = c+d;
	}
}


int main(){
	ll n;
	cin >> n;
	ll ans[2] = {0};
	fast_fib(n, ans);
	cout << ans[0] << endl;

return 0;
}
