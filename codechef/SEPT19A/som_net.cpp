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
int main()
{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		ll t = 1;
		cin >> t;
		while(t--)
		{
			
    ll n, m;
    cin >> n >> m;
    ll maxEdge = ((n * (n + 1LL)) / 2LL);
    if(m == maxEdge) {
      cout << n << '\n';
      continue;
    } else if(maxEdge < m || m < (n - 1LL)) {
      cout << -1 << '\n';
      continue;
    } else if(m == 0) {
      cout << 0 << '\n';
      continue;
    } else if(m == 1) {
      cout << 1 << '\n';
      continue;
    }
    m -= (n - 1) + 2;
    ll ans = 2;
    if(m > 0) {
      m -= max(0LL, n - 2);
      ans++;
    }
    m--;
    ll first = (n % 2 == 0) ? n / 2  : n / 2;
    ll second = n - first;
    while(m > 0) {
      m -= first;
      ans++;
      if(m > 0) {
        m -= second;
        ans++;
      }
    }
    cout << ans << '\n';
		}
	return 0;
}
	
