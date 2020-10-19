#include<bits/stdc++.h>
using namespace std;
typedef unsigned int ll;
typedef double dd;
const long long INF = 1e18L + 5;
const int siz = 1e5 + 5;
vector <ll> edges[siz];
vector <ll> in_degree(siz);
int dist[siz];
bool vis[siz];
void solve();
ll MOD = 10;
ll fib[2];




ll a,b,c,d;

unsigned int log22(unsigned int n)
{
		return (n > 1) ? 1 + log22(n/2) : 0;
}

// Hackerearth fast_dubling method for fast fib
void fast_fib(ll n,ll ans[])
{
    if(n == 0)
    {
        ans[0] = 0;
        ans[1] = 1;
        return;
    }
    fast_fib((n/2),ans);
    a = ans[0];             /* F(n) */
    b = ans[1];             /* F(n+1) */
    c = 2*b - a;
    if(c < 0)
        c += MOD;
    c = (a * c) % MOD;      /* F(2n) */
    d = (a*a + b*b) % MOD;  /* F(2n + 1) */
    if(n%2 == 0)
    {
        ans[0] = c;
        ans[1] = d;
    }
    else
    {
        ans[0] = d;
        ans[1] = c+d;
    }
}



void solve()
{
	ll n;
	cin >> n;
			fib[0] = 0, fib[1] = 1;
ll pos = pow(2, log22(n));
fast_fib(pos-1, fib);
	cout << fib[0] << endl;

}

int main()
{
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
	
