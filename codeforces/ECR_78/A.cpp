#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;
const ll INF = 1e18L + 5;
const int siz = 1e5 + 5;
map<char,int> pos;
map<int,int> vis;
void solve()
{
	ll n;
		cin >> n;
		ll a[100000], fre[100000];
		for (ll i = 1; i <= 2048; i *= 2) {
			fre[i] = 0;
		}
 
		for (ll i = 1; i <= n; i++) {
			cin >> a[i];
 
			if (a[i] <= 2048) {
				fre[a[i]]++;
			}
		}
 
		for (ll i = 2; i <= 2048; i *= 2) {
			fre[i] += fre[i / 2] / 2;
		}
 
		if (fre[2048] > 0) {
			cout << "YES\n";
		} 
		else 
		{
			cout << "NO\n";
		}
 
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

