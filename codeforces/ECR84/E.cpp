/* Read input from STDIN. Print your output to STDOUT*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define deb(x) cout << #x <<  " " << x << endl; 
void solve(){
    ll n;
    cin >> n;
    unordered_map<ll, ll>ch;
    ll g[n];
    for(ll &i : g) cin >> i, ch[i]++;
    ll o[n];
    for(ll &i : o) cin >> i;
    sort(g, g+n);
    sort(o, o+n);
    ll ans = 0;
    ll G[n] = {0};
    G[n-1] = (g[n-1] > o[n-1]);
    for(int i = n-2; i >= 0; i--){
		G[i] = G[i+1] + (g[i] > o[i]);
	}
	
     for(ll i : g) cout << i << " ";
     cout << endl;
     for(ll i : o) cout << i << " ";
     cout << endl;
    for(ll i = 0; i < n; i++){
	cout << G[i] << " ";
    }
    cout << endl;
    cout << ans << endl;
}
int main(int argc, char *a[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //Write code here
    int t;
    cin >> t;
    while(t--)
        solve();
}
