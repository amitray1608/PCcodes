#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e5 + 5;
vector <ll> edges[siz];
vector <ll> in_degree(siz);
int dist[siz];
bool vis[siz];
void solve();
ll mod = 1e9+7;
	vector <ll> fib(10000005);

void solve()
{
	ll n;
	cin >> n;

ll pos = pow(2, (ll)log2(n));
	cout << fib[pos-1] << endl;

}

int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
			fib[0] = 0, fib[1] = 1;
	for(ll i = 2; i<10000005; i++){
		fib[i] = (fib[i-1] + fib[i-2])%10;}
		while(t--)
		{
			solve();
		}
	return 0;
}
	
