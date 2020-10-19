#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e6 + 5;
    long long int MOD = 1e9 + 7; 

#define deb(x) cout << #x << "x = " << x << endl;
//geeks for geeks code


ll a[siz] ={0};
ll fact[siz] ={0};

long long moduloMultiplication(long long a, 
                            long long b, 
                            long long mod) 
{ 
    long long res = 0; // Initialize result 
  
    // Update a if it is more than 
    // or equal to mod 
    a %= mod; 
  
    while (b) 
    { 
        // If b is odd, add a with result 
        if (b & 1) 
            res = (res + a) % mod; 
  
        // Here we assume that doing 2*a 
        // doesn't cause overflow 
        a = (2 * a) % mod; 
  
        b >>= 1; // b = b / 2 
    } 
  
    return res; 
} 

void solve()
{
	ll n;
	cin >> n;
	cout << fact[n] << endl;
}

int main()
{
	a[1]=1;
	fact[1]=1;
	for(ll i = 2; i<=1000000; i++)
		{
			a[i] = moduloMultiplication(i, a[i-1], MOD);
			fact[i] = moduloMultiplication(fact[i-1], a[i], MOD);
			}
		
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		while(t--)
		{
			solve();
		}
	return 0;
}
	
