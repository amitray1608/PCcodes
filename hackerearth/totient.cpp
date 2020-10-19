//“Make it work, make it right, make it fast.” – Kent Beck
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long ll;
typedef double dd;
const int siz = 1e6 + 5;
const int MOD = 1e9 + 7;
#define deb(x) cout << #x << " = " << x << endl;
//0(NlogN) for phi function
int  phi(int n){
	int ans = 1;
	    for(int i = 2; i<=n; i++)   
        if(__gcd(i, n) == 1)    ans++; 	

	return ans;
}

int phi_f(int n){
	float result = n;
	for(int p = 2; p*p <= n; p++){
		if(n%p == 0){
			while(n%p == 0) n /= p;
				result *= (1.0 - (1.0/(float)p));
		}
	}
	if(n > 1)
		result *= (1.0 - (1.0 / (float)n));
		
	return (int) result;
}

ll phi_i(ll n){
	ll result = n;
	for(ll p = 2; p*p <= n; ++p){
		if(n%p == 0){
			while(n%p == 0)	n/=p;
			
			result -= result/p;
		}
	}
	if(n > 1)
		result -= result/n;
		
	return result;
}
bool is_prime(ll n){
	for(ll i = 2; i*i <= n; i++){
		if(n%i==0)
			return false;
	}
	return true;
}
 
void solve()
{
	ll n, k;
	cin >> n >> k;
	//seive(n);
	ll ans = n;
	
	while(k--){
		ans = phi_i(ans);
		if(is_prime(ans)){
			ans = ans-1;
			break;
		}
		if(ans == 1){
			break;
		}
	}
	cout << ans  << endl;
}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int t = 1;
		cin >> t;
		while(t--)
		{
			solve();
		}
}
